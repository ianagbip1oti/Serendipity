COMPILER=g++
CXXFLAGS+=-g -Wall -Iinclude -pedantic-errors
SOURCE=$(wildcard src/*.cpp)
BINARIES=bin/serendipity.exe

all:
	@# 'echo' and 'rm' still works on windows
	@# if you're running cmder (like myself) or cygwin
	@echo Compiling...
	@$(COMPILER) $(CXXFLAGS) $(SOURCE) -o bin/serendipity

clean:
	rm $(BINARIES)