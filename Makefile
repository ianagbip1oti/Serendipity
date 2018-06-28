COMPILER=g++
CXXFLAGS+=-g -Wall -Iinclude -pedantic-errors -Wextra
SOURCE=$(wildcard src/*.cpp)
BINARIES=bin/serendipity.exe

all:
	@echo Compiling...
	@$(COMPILER) $(CXXFLAGS) $(SOURCE) -o bin/serendipity
	@echo Done

clean:
	rm bin/serendipity.*

