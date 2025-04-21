# To Compile

## g++ compilation

* Module file somehow needs to be .cpp for g++
* If you want to use std module. Precompile them first. For example, I wanted to import <iostream>;
* g++ does not support "import std" yet. So, need to compile individual module like iostream

### To Compile
```
g++ -std=c++20 -fmodules-ts -xc++-system-header iostream
```
```
g++ -std=c++20 -fmodules-ts .\MathAlgebra.cpp .\MathGeometry.cpp .\Math.cpp .\main.cpp -o program.exe
```

## For MSVC cl.exe

* File extension for module must be .ixx
* others can be .cpp eg main.cpp
* Compile std to enable us to import

### To compile std.ixx on VC on command prompt
```
cl /std:c++latest /EHsc /nologo /W4 /c "%VCToolsInstallDir%\modules\std.ixx"
```

### To compile std.ixx on VC on powershell

```
cl /std:c++latest /EHsc /nologo /W4 /c "$env:VCToolsInstallDir\modules\std.ixx"
```

or

```
cl /std:c++latest /EHsc /nologo /W4 /c "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.42.34433\modules\std.ixx"
```

### One Liner
```
cl /Feprogram.exe /std:c++latest /EHsc /nologo /W4 "%VCToolsInstallDir%\modules\std.ixx" .\MathAlgebra.ixx .\MathGeometry.ixx .\Math.ixx .\main.cpp
```

### Powershell
cl /Feprogram.exe /std:c++latest /EHsc /nologo /W4 $env:VCToolsInstallDir\modules\std.ixx .\MathAlgebra.ixx .\MathGeometry.ixx .\Math.ixx .\main.cpp