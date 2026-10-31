@echo off
call "C:\Program Files\Microsoft Visual Studio\18\Community\Common7\Tools\VsDevCmd.bat"
if not defined VCToolsInstallDir (
    echo VCToolsInstallDir was not set.
    exit /b 1
)
if not exist "%VCToolsInstallDir%\modules\std.ixx" (
    echo Could not find:
    echo %VCToolsInstallDir%\modules\std.ixx
    exit /b 1
)
cl.exe /nologo /std:c++latest /EHsc /W4 /c "%VCToolsInstallDir%\modules\std.ixx"
if errorlevel 1 exit /b %errorlevel%