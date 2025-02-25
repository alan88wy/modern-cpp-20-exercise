# Modern C++20/23 Exercise

MSVC 2022 config (c_cpp_properties.json):


{
    "configurations": [
        {
            "name": "Win32",
            "includePath": [
                "${workspaceFolder}/**"
            ],
            "defines": [
                "_DEBUG",
                "UNICODE",
                "_UNICODE"
            ],
            "windowsSdkVersion": "10.0.26100.2454",
            "compilerPath": "C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.29.30133/bin/Hostx64/x64/cl.exe",
            "cStandard": "c17",
            "cppStandard": "c++23",
            "intelliSenseMode": "windows-msvc-x64"
        }
    ],
    "version": 4
}

tasks.json:

{
	"version": "2.0.0",
	"tasks": [
		{
			"type": "cppbuild",
			"label": "Build with GCC",
			"command": "C:\\Users\\alan\\scoop\\apps\\mingw-winlibs\\current\\bin\\g++.exe",
			"args": [
				"-g",
				"-std=c++23",
				"${file}",
				"-o",
				"${fileDirname}\\${fileBasenameNoExtension}.exe"
			],
			"options": {
				"cwd": "${fileDirname}"
			},
			"problemMatcher": [
				"$gcc"
			],
			"group": "build",
			"detail": "compiler: C:\\Users\\alan\\scoop\\apps\\mingw-winlibs\\current\\bin\\g++.exe"
		}
	]
}