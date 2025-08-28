@echo off
echo Building vampiregame in Release mode...

REM Configure the project
echo Configuring project...
cmake --preset win-msvc
if %errorlevel% neq 0 (
    echo Error: Configuration failed!
    pause
    exit /b 1
)

REM Build the project
echo Building project...
cmake --build --preset build --config Release
if %errorlevel% neq 0 (
    echo Error: Build failed!
    pause
    exit /b 1
)

echo Build completed successfully!
echo Executable location: build\win-msvc\Release\game.exe
