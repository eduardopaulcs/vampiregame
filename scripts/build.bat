@echo off

REM Change to project root directory
cd /d "%~dp0.."

REM Check if clean build is requested
if "%1"=="clean" goto :clean_build
goto :normal_build

:normal_build
echo Building game in Debug mode...
echo.

REM Configure the project
echo Configuring project...
cmake --preset win-msvc
if %errorlevel% neq 0 (
    echo Error: Configuration failed!
    exit /b 1
)

REM Build the project
echo Building project...
cmake --build --preset build --config Debug
if %errorlevel% neq 0 (
    echo Error: Build failed!
    exit /b 1
)

echo Build completed successfully!
echo Executable location: build\win-msvc\Debug\game.exe
goto :end

:clean_build
echo Clean building game in Debug mode...
echo.

REM Remove build directory completely
if exist "build" (
    rmdir /s /q "build"
)

REM Configure the project
echo Configuring project...
cmake --preset win-msvc
if %errorlevel% neq 0 (
    echo Error: Configuration failed!
    exit /b 1
)

REM Build the project
echo Building project...
cmake --build --preset build --config Debug
if %errorlevel% neq 0 (
    echo Error: Build failed!
    exit /b 1
)

echo Clean build completed successfully!
echo Executable location: build\win-msvc\Debug\game.exe
goto :end

:end
echo.
