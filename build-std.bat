@echo off
setlocal

call "C:\Program Files\Microsoft Visual Studio\18\Community\Common7\Tools\VsDevCmd.bat"

if not exist "%~dp0build" mkdir "%~dp0build"

echo Building std module...

cl.exe /nologo /std:c++latest /EHsc /c ^
    /ifcOutput "%~dp0build\" ^
    "%VCToolsInstallDir%\modules\std.ixx"

if errorlevel 1 exit /b %errorlevel%

echo Building print header unit...

pushd "%~dp0build"

cl.exe /nologo /std:c++latest /EHsc ^
    /exportHeader ^
    /headerName:angle print

if errorlevel 1 (
    popd
    exit /b %errorlevel%
)

popd

echo Modules built successfully.
