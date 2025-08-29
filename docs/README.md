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

2. **vcpkg** (Package manager for C++)
   - Install vcpkg by running these commands in PowerShell:
     ```powershell
     git clone --depth 1 --branch 2025.07.25 https://github.com/Microsoft/vcpkg.git C:\vcpkg-vampiregame
     C:\vcpkg-vampiregame\bootstrap-vcpkg.bat
     ```

3. **MSYS2** (for debugging support)
   - Download from: https://www.msys2.org/
   - After installation, open MSYS2 MinGW x64 and run:
     ```bash
     pacman -Syu
     pacman -S mingw-w64-x86_64-gdb
     ```
   - This is required to execute the launch.json options

4. **Recommended Extensions** (for VS Code/Cursor)
   - clangd (C++ language server)
   - CMake Tools
   - Hex Editor

### Scripts

The project includes convenient batch scripts for building and running the game:

#### Build
```bash
scripts/build.bat
```
- Installs dependencies from `vcpkg.json`
- Configures the project if needed
- Builds in Debug mode
- Output: `build/win-msvc/Debug/game.exe`

#### Run
```bash
scripts/run.bat
```
- Runs the previously built `.exe` file

### Project Structure

```
vampiregame/
├── src/
│   ├── main.cpp              # Entry point
│   ├── game/                 # Game management
│   ├── engine/               # Core engine systems
│   ├── entities/             # Game entities
│   ├── systems/              # Game systems
│   └── utils/                # Utility classes
├── assets/                   # Game assets
│   ├── textures/             # Image files
│   ├── sounds/               # Sound effects
│   ├── music/                # Background music
│   └── fonts/                # Font files
├── scripts/                  # Build and run scripts
└── docs/                     # Documentation
```
