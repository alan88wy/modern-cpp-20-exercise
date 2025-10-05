# Compiler settings

## g++

C:\Users\alan\scoop\apps\mingw-winlibs-ucrt\current\bin\g++.exe 
flag for C: -Wall -Wextra -g3
flag for c++: -std=c++23 -fmodules 

### For Code Runner:
// "cpp": "cd $dir && g++ -std=c++23 -lstdc++exp -fdiagnostics-color=always -g $fileName -o $fileNameWithoutExt.exe && $dir$fileNameWithoutExt.exe",
// "cpp": "cd $dir && g++ -std=c++23 -fdiagnostics-color=always -Wall -Wextra -g3 $fileName -o $fileNameWithoutExt.exe && $dir$fileNameWithoutExt.exe",
// for using coroutine - -std=c++20 -fcoroutines
// "cpp": "cd $dir && g++ -std=c++23 -fcoroutines -p thread -fdiagnostics-color=always -Wall -Wextra -g3 $fileName -o $fileNameWithoutExt.exe && $dir$fileNameWithoutExt.exe",


# MSVC 

# For Code RUnner
//"cpp": "cd $dir && cl.exe /Ferooster.exe /std:c++latest /EHsc /nologo /W4 \"C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\tools\\msvc\\14.44.35207\\modules\\std.ixx\" $fileName && rooster.exe",
"cpp": "cd $dir && cl.exe /Fe$fileNameWithoutExt.exe /std:c++latest /EHsc /nologo /W4 \"C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\tools\\msvc\\14.44.35207\\modules\\std.ixx\" $fileName && $dir$fileNameWithoutExt.exe",
