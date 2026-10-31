@echo off
setlocal

if "%~1"=="" (
    echo Usage: build-app.bat source-file.cpp
    exit /b 1
)

call "C:\Program Files\Microsoft Visual Studio\18\Community\Common7\Tools\VsDevCmd.bat"

set "SOURCE=%~1"
set "OUTPUT=%~dpn1.exe"
set "MODULE_DIR=%~dp0build"

if not exist "%MODULE_DIR%\std.ifc" (
    echo Missing: "%MODULE_DIR%\std.ifc"
    echo Run build-modules.bat first.
    exit /b 1
)

if not exist "%MODULE_DIR%\std.obj" (
    echo Missing: "%MODULE_DIR%\std.obj"
    echo Run build-modules.bat first.
    exit /b 1
)

if not exist "%MODULE_DIR%\print.ifc" (
    echo Missing: "%MODULE_DIR%\print.ifc"
    echo Run build-modules.bat first.
    exit /b 1
)

echo Compiling:
echo   Source: "%SOURCE%"
echo   Output: "%OUTPUT%"

cl.exe /nologo /std:c++latest /EHsc /W4 ^
    /reference "std=%MODULE_DIR%\std.ifc" ^
    /headerUnit:angle print="%MODULE_DIR%\print.ifc" ^
    /Fe:"%OUTPUT%" ^
    "%SOURCE%" ^
    "%MODULE_DIR%\std.obj"

exit /b %errorlevel%
