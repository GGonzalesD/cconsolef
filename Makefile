# Variables
COMPILER = g++
STD = -std=gnu++17
BINARY = src/main
MAINFILE = main.cpp
SOURCES = cconsolef.cpp

HEADERS = cconsolef.h
FLAGS = -pthread

# All
all: mainProgram run

# Compilar programa
mainProgram: $(HEADERS) $(MAINFILE) $(SOURCES)
	$(COMPILER) $(STD) $(MAINFILE) $(SOURCES) $(FLAGS) -o $(BINARY) 

clear:
	rm -f src/*

run:
	./src/main
