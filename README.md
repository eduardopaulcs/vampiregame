# vampiregame

## Development

This project is designed to be developed on Windows 10 using VS Code or Cursor.

### Prerequisites

Before you begin, ensure you have the following installed:

1. **Visual Studio 2022** (Community, Professional, or Enterprise)
   - Download from: https://visualstudio.microsoft.com/downloads/
   - During installation, make sure to include:
     - "Desktop development with C++" workload
   - This automatically installs Build Tools, CMake, and MSVC compiler

2. **MSYS2** (for debugging support)
   - Download from: https://www.msys2.org/
   - After installation, open MSYS2 MinGW x64 and run:
     ```bash
     pacman -Syu
     pacman -S mingw-w64-x86_64-gdb
     ```
   - This is required to execute the launch.json options, particularly useful for debug mode

3. **Recommended Extensions** (for VS Code/Cursor)
   - clangd (C++ language server)
   - CMake Tools
   - Hex Editor

### Build Scripts

The project includes convenient batch scripts for building:

#### Debug Build
```bash
build-debug.bat
```
- Configures the project if needed
- Builds in Debug mode
- Output: `build/win-msvc/Debug/game.exe`

#### Release Build
```bash
build-release.bat
```
- Configures the project if needed
- Builds in Release mode
- Output: `build/win-msvc/Release/game.exe`
