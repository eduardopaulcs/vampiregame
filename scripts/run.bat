@echo off

REM Change to project root directory
cd /d "%~dp0.."

if exist "build\win-msvc\Debug\game.exe" (
    echo Running game...
    cd build\win-msvc\Debug
    game.exe
    echo Game finished!
) else (
    echo Error: No game.exe found. Please build the project first.
    echo Use: scripts\build.bat
)
