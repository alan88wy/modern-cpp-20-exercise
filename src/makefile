# Generic makefile to compile a single c/c++ program
# Usage: make s=<program> without the extension

ifeq ($(OS),Windows_NT)
     out = $(s).exe
else
     out = $(s)
endif

ifeq ($(wildcard $(s).c), $(s).c)
   CC=clang
   in = $(s).c
endif

ifeq ($(wildcard $(s).cpp), $(s).cpp)
   CC=g++
   in = $(s).cpp
endif

.PHONY: build
build: 
	$(CC) -o $(out) $(in)
