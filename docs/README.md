# vampiregame

## Development

This project should be developed on Windows 10 using VS Code or Cursor.

### Prerequisites

Before you begin, ensure you have the following installed:

1. **Visual Studio**
   - Download from: https://visualstudio.microsoft.com/downloads/
   - During installation, make sure to include the "Desktop development with C++" workload

2. **Visual Studio Build Tools**
   - Download from: https://visualstudio.microsoft.com/downloads/
   - Scroll down to All Downloads > Tools for Visual Studio, and download "Build Tools for Visual Studio"
   - During installation, make sure to include the "Desktop development with C++" workload

2. **vcpkg**
   - Install vcpkg by running these commands in PowerShell:
     ```powershell
     git clone --depth 1 --branch 2025.07.25 https://github.com/Microsoft/vcpkg.git C:\vcpkg-vampiregame
     ```
     ```powershell
     C:\vcpkg-vampiregame\bootstrap-vcpkg.bat
     ```

3. **MSYS2** (optional)
   - Download from: https://www.msys2.org/
   - After installation, open MSYS2 MinGW x64 and run:
     ```bash
     pacman -Syu
     ```
     ```bash
     pacman -S mingw-w64-x86_64-gdb
     ```
   - This is required to use the launch options integrated in the IDE

4. **Recommended Extensions** (VS Code/Cursor)
   - clangd
   - CMake Tools
   - Hex Editor

### Building and Running

#### Command Line Scripts

The project includes convenient batch scripts for building and running the game:

**Build Scripts:**

**_Build:_**
```bash
scripts/build.bat
```
- Configures the project if needed
- Installs dependencies from `vcpkg.json`
- Builds in Debug mode
- Output: `build/win-msvc/Debug/game.exe`

**_Clean Build:_**
```bash
scripts/build.bat clean
```
- Deletes the build folder
- Configures the project
- Installs dependencies from `vcpkg.json`
- Builds in Debug mode
- Output: `build/win-msvc/Debug/game.exe`

**Run Script:**

```bash
scripts/run.bat
```
- Runs the previously built `.exe` file

#### IDE Launch Options

The project includes VS Code launch configurations:

**Prerequisites:**
- MSYS2 must be installed with MinGW-w64 toolchain
- GDB debugger should be available at `C:\msys64\mingw64\bin\gdb.exe`

**Available Debug Configurations:**
- **Debug**: Standard debug build and launch
- **Debug Clean**: Clean build before debugging

The debugger will automatically build the project and launch the executable with full debugging capabilities.
