param(
    [string]$Problem = "",
    [ValidateSet("Debug", "Release", "RelWithDebInfo", "MinSizeRel")]
    [string]$Configuration = "Debug",
    [switch]$NoBuild
)

$ErrorActionPreference = "Stop"

$repoRoot = Split-Path -Parent $PSScriptRoot
Push-Location $repoRoot

try {
    cmake -S . -B build

    if (-not $NoBuild) {
        cmake --build build --config $Configuration
    }

    $ctestArgs = @(
        "--test-dir", "build",
        "-C", $Configuration,
        "--output-on-failure"
    )

    if ($Problem.Trim().Length -gt 0) {
        $ctestArgs += @("-L", "^$([regex]::Escape($Problem.Trim()))$")
    }

    ctest @ctestArgs
}
finally {
    Pop-Location
}
