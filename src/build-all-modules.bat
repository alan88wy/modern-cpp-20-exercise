@echo off
setlocal
call "C:/Program Files/Microsoft Visual Studio/18/Community/VC/Auxiliary/BuildVsDevCmd.bat"
if not defined VCToolsInstallDir (
    echo VCToolsInstallDir was not set.
    exit /b 1
)
set "ROOT=%~dp0"
set "MODULE_DIR=%ROOT%build"
set "STD_SOURCE=%VCToolsInstallDir%modules\std.ixx"
if not exist "%MODULE_DIR%" mkdir "%MODULE_DIR%"
echo VCToolsInstallDir:
echo "%VCToolsInstallDir%"
echo Standard module source:
echo "%STD_SOURCE%"
if not exist "%STD_SOURCE%" (
    echo std.ixx was not found.
    exit /b 1
)
echo Building std module...
pushd "%VCToolsInstallDir%modules"
cl.exe /nologo /std:c++latest /EHsc /c /Fo"%MODULE_DIR%\std.obj" /ifcOutput "%MODULE_DIR%" std.ixx
set "RESULT=%errorlevel%"
popd
if not "%RESULT%"=="0" exit /b %RESULT%
echo Building print header unit...
pushd "%MODULE_DIR%"
cl.exe /nologo /std:c++latest /EHsc /exportHeader /headerName:angle print
set "RESULT=%errorlevel%"
popd
if not "%RESULT%"=="0" exit /b %RESULT%
echo Modules built successfully.
dir "%MODULE_DIR%\*.ifc"
dir "%MODULE_DIR%\*.obj"
