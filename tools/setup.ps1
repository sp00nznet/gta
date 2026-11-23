# One-click setup for Grand Theft Auto, recompiled. Run it by double-clicking
# Setup.cmd in the repo folder; the README's Getting Started is the same thing
# by hand. Adapted from Gunman Chronicles' recomp.
#
# It checks for what the build needs (Python 3 with pefile and capstone, the
# pcrecomp toolkit beside this repo, Visual Studio's C++ build tools with
# CMake) and asks before installing anything. Then: extract the game from
# Rockstar's freeware installer, lift, patch, build, and a "Grand Theft Auto
# (recomp)" shortcut in this folder. Finished steps are skipped (-Force redoes
# them); everything goes to setup.log.
#
# For recomp-launcher: -Yes installs what is missing without asking, -Game is
# GTAINSTALLER.zip, a folder holding data1.cab, or an extracted game (the
# folder with WINO\Grand Theft Auto.exe), and RECOMP_LAUNCHER=1 skips "Press
# Enter to close".
param([switch]$Force, [switch]$Yes, [Alias('GameDir')][string]$Game = "")

$ErrorActionPreference = 'Stop'
$Root = Split-Path -Parent $PSScriptRoot
# pcrecomp: $env:PCRECOMP, else ../pcrecomp-gta, else ../pcrecomp (where the
# launcher puts it). tools/lift.py and CMake look in the same places.
$Toolkit = $env:PCRECOMP
if (-not $Toolkit) {
  $Toolkit = Join-Path (Split-Path -Parent $Root) 'pcrecomp-gta'
  if (-not (Test-Path (Join-Path $Toolkit 'tools\lift\drive32.py'))) { $Toolkit = Join-Path (Split-Path -Parent $Root) 'pcrecomp' }
}
$env:PCRECOMP = $Toolkit
$Log = Join-Path $Root 'setup.log'
Set-Location $Root
function Log($t) { Add-Content -Path $Log -Value $t -Encoding UTF8 }
Log "==== setup $(Get-Date -Format s)"

function Say($t, $c = 'Gray') { Write-Host $t -ForegroundColor $c; Log $t }
function Step($n, $t) { Write-Host ""; Say "[$n/6] $t" 'Cyan' }
function Done { if (-not $env:RECOMP_LAUNCHER) { Read-Host "Press Enter to close" | Out-Null } }
function Fail($t) {
  Say ""; Say "Setup stopped: $t" 'Red'
  Say "The details are in $Log. Fix that and run Setup.cmd again; finished steps are skipped." 'Yellow'
  Done; exit 1
}
function Ask($q) {   # Enter = yes; -Yes answers it
  if ($Yes) { Say "$q yes (-Yes)"; return $true }
  $a = Read-Host "$q [Y/n]"; return -not ($a -match '^[nN]')
}
function Refresh-Path {
  $env:Path = [Environment]::GetEnvironmentVariable('Path', 'Machine') + ';' + [Environment]::GetEnvironmentVariable('Path', 'User')
}
# A native program's output into the log. Windows PowerShell turns its stderr
# into errors, so 'Stop' is off while it runs.
function Exec([string[]]$cmd) {
  $old = $ErrorActionPreference; $ErrorActionPreference = 'Continue'
  $rest = @($cmd | Select-Object -Skip 1)
  & $cmd[0] @rest 2>&1 | ForEach-Object { Log "$_" }
  $code = $LASTEXITCODE
  $ErrorActionPreference = $old
  return $code
}
function Run($what, [string[]]$cmd) {
  Say "  $what..."
  $code = Exec $cmd
  if ($code -ne 0) { Fail "$what failed (exit code $code)." }
}
function Winget($id, $extra) {
  if (-not (Get-Command winget -ErrorAction SilentlyContinue)) {
    Fail "winget is missing. Install 'App Installer' from the Microsoft Store, or install $id yourself."
  }
  Exec (@('winget', 'install', '-e', '--id', $id, '--accept-package-agreements', '--accept-source-agreements') + $extra) | Out-Null
  Refresh-Path
}

if (-not $env:RECOMP_LAUNCHER) { Clear-Host }
Say "Grand Theft Auto: static recompilation setup" 'White'
Say "You need the game: Rockstar's freeware GTAINSTALLER.zip (see the README) or your own disc."
Say "This takes about 20 minutes and 3 GB, most of it the one-time lift and build."

# ---------------------------------------------------------------- tools
Step 1 "Checking the tools the build needs"
function Find-Python {
  foreach ($c in @(@('py', '-3'), @('python'), @('python3'))) {
    if (-not (Get-Command $c[0] -ErrorAction SilentlyContinue)) { continue }
    $old = $ErrorActionPreference; $ErrorActionPreference = 'Continue'
    $rest = @($c | Select-Object -Skip 1)
    $v = (& $c[0] @rest --version 2>&1 | Out-String).Trim()
    $ErrorActionPreference = $old
    if ($v -match '^Python 3\.(\d+)' -and [int]$Matches[1] -ge 10) { return ,$c }
  }
  return $null
}
$pyargs = Find-Python
if (-not $pyargs) {
  Say "  Python 3 is not installed."
  if (-not (Ask "  Install Python 3.12 now (winget, for your user only)?")) { Fail "Python 3 is required." }
  Winget 'Python.Python.3.12' @('--scope', 'user')
  $pyargs = Find-Python
  if (-not $pyargs) { Fail "Python installed, but Windows has not picked it up yet: close this window and run Setup.cmd again." }
}
Say "  Python: $($pyargs -join ' ')"

if ((Exec ($pyargs + @('-c', 'import pefile, capstone'))) -ne 0) {
  Say "  The Python packages pefile and capstone are missing."
  if (-not (Ask "  Install them now (pip, for your user only)?")) { Fail "pefile and capstone are required." }
  Run "Installing pefile and capstone" ($pyargs + @('-m', 'pip', 'install', '--user', 'pefile', 'capstone'))
}

if (-not (Test-Path (Join-Path $Toolkit 'tools\lift\drive32.py'))) {
  Say "  The pcrecomp toolkit is not beside this folder ($Toolkit)."
  if (-not (Ask "  Download it now?")) { Fail "pcrecomp is required at $Toolkit." }
  if (Get-Command git -ErrorAction SilentlyContinue) {
    Run "Cloning pcrecomp" @('git', 'clone', '--depth', '1', '-b', 'gta', 'https://github.com/sp00nznet/pcrecomp', $Toolkit)
  } else {
    $zip = Join-Path $env:TEMP 'pcrecomp.zip'
    Say "  Downloading pcrecomp..."
    Invoke-WebRequest 'https://github.com/sp00nznet/pcrecomp/archive/refs/heads/gta.zip' -OutFile $zip -UseBasicParsing
    $tmp = Join-Path $env:TEMP 'pcrecomp-unzip'
    Remove-Item $tmp -Recurse -Force -ErrorAction SilentlyContinue
    Expand-Archive $zip $tmp
    Move-Item (Join-Path $tmp 'pcrecomp-gta') $Toolkit
  }
}
Say "  pcrecomp: $Toolkit"

$vswhere = Join-Path ${env:ProgramFiles(x86)} 'Microsoft Visual Studio\Installer\vswhere.exe'
function VS-Path {
  if (-not (Test-Path $vswhere)) { return $null }
  return & $vswhere -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 Microsoft.VisualStudio.Component.VC.CMake.Project -property installationPath
}
if (-not (VS-Path)) {
  Say "  Visual Studio's C++ build tools (with CMake) are not installed."
  Say "  They are free, about 6 GB, and need an administrator prompt."
  if (-not (Ask "  Install Visual Studio 2022 Build Tools now (winget)?")) { Fail "The C++ build tools are required." }
  Winget 'Microsoft.VisualStudio.2022.BuildTools' @('--override', '--passive --wait --add Microsoft.VisualStudio.Workload.VCTools --add Microsoft.VisualStudio.Component.VC.CMake.Project --includeRecommended')
  if (-not (VS-Path)) { Fail "The build tools did not finish installing. Run Setup.cmd again once the Visual Studio Installer is done." }
}
$cmake = 'cmake'
if (-not (Get-Command cmake -ErrorAction SilentlyContinue)) {
  $cmake = Join-Path (VS-Path) 'Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe'
}
Say "  C++ build tools: found"

# ---------------------------------------------------------------- game
Step 2 "Extracting the game"
$Wino = Join-Path $Root 'game\extracted_full\WINO'
$Exe = Join-Path $Wino 'Grand Theft Auto.exe'
if ((Test-Path $Exe) -and -not $Force) {
  Say "  Already extracted in game\extracted_full (skipping)."
} else {
  $g = $Game.Trim('"', ' ')
  while (-not $g) {
    if ($Yes) { Fail "no game given: choose GTAINSTALLER.zip, a folder with data1.cab, or the extracted game." }
    $g = (Read-Host "  Path of GTAINSTALLER.zip (or a folder holding data1.cab)").Trim('"', ' ')
  }
  New-Item -ItemType Directory -Force (Join-Path $Root 'game') | Out-Null
  if (Test-Path (Join-Path $g 'WINO\Grand Theft Auto.exe')) {          # already extracted
    Say "  Copying the extracted game from $g"
    New-Item -ItemType Directory -Force (Join-Path $Root 'game\extracted_full') | Out-Null
    Copy-Item (Join-Path $g '*') (Join-Path $Root 'game\extracted_full') -Recurse -Force
  } else {
    $cabs = $g
    if ($g -match '\.zip$') {
      $cabs = Join-Path $Root 'game\installer'
      Say "  Unzipping $g"
      Expand-Archive $g $cabs -Force
    }
    if (-not (Test-Path (Join-Path $cabs 'data1.cab'))) { Fail "no data1.cab in ${cabs}: that is not GTA's installer." }
    Run "Extracting the installer's cabinets" ($pyargs + @((Join-Path $Toolkit 'tools\assets\isextract.py'),
        (Join-Path $cabs 'data1.cab'), (Join-Path $cabs 'data1.cab'), '-o', (Join-Path $Root 'game\extracted_full')))
  }
  if (-not (Test-Path $Exe)) { Fail "the extracted game has no WINO\Grand Theft Auto.exe." }
}

# ---------------------------------------------------------------- build
Step 3 "Translating the game's code to C (about 12 minutes, once)"
if ((Test-Path 'src\recomp\gen\recomp_dispatch.c') -and -not $Force) { Say "  Already done (skipping)." }
else { Run "Lifting" ($pyargs + @('tools\lift.py', $Exe)) }

Step 4 "Applying the remaster's patches"
Run "Patching" ($pyargs + @('tools\patch_gen.py'))

Step 5 "Compiling (10-20 minutes the first time)"
if (-not (Test-Path 'build\CMakeCache.txt')) { Run "Configuring" @($cmake, '-B', 'build', '-G', 'Visual Studio 17 2022', '-A', 'Win32') }
Run "Building" @($cmake, '--build', 'build', '--config', 'Release', '--target', 'gta1')
$Bin = Join-Path $Root 'build\bin\Release\gta1.exe'
if (-not (Test-Path $Bin)) { Fail "the build did not produce build\bin\Release\gta1.exe." }

# ---------------------------------------------------------------- shortcut
Step 6 "Making a shortcut"
$lnk = Join-Path $Root 'Grand Theft Auto (recomp).lnk'
$sh = New-Object -ComObject WScript.Shell
$s = $sh.CreateShortcut($lnk)
$s.TargetPath = $Bin
$s.Arguments = '"Grand Theft Auto.exe"'
$s.WorkingDirectory = $Wino
$s.IconLocation = $Exe + ',0'
$s.Description = 'Grand Theft Auto, statically recompiled'
$s.Save()
Say "  $lnk"

Write-Host ""
Say "Done. Double-click 'Grand Theft Auto (recomp)' in this folder to play." 'Green'
Say "In game: F10 settings (resolution, scaling, controller), F11 fullscreen, F12 scaling."
Done
