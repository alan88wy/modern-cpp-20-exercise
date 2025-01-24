# To Compile

### Importnt

Module file somehow needs to be .cpp for g++
If you want to use std module. Precompile them first.
For example, I wanted to import <iostream>;
I will compile it first:

g++ -std=c++20 -fmodules-ts -xc++-system-header iostream


g++ -std=c++20 -fmodules-ts .\MathAlgebra.cpp .\MathGeometry.cpp .\Math.cpp .\main.cpp -o program.exe

