@echo off
setlocal
if "%~1"=="" (
    echo Usage: build-app.bat source-file.cpp
    exit /b 1
)
if /I not "%~x1"==".cpp" (
    echo Error: expected a .cpp file, got "%~x1"
    exit /b 1
)
set "SOURCE=%~1"
set "OUTPUT=%~dpn1.exe"

call "C:\Program Files\Microsoft Visual Studio\18\Community\Common7\Tools\VsDevCmd.bat"
if not defined VCToolsInstallDir (
    echo VCToolsInstallDir was not set.
    exit /b 1
)
echo Compiling:
echo   Source: "%SOURCE%"
echo   Output: "%OUTPUT%"
cl.exe /nologo /std:c++latest /EHsc /W4 ^
    /Fe:"%OUTPUT%" ^
    "%SOURCE%"
exit /b %errorlevel%
