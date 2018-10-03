file = basic_benchmarks.c
executable = basic_benchmarks.out
arguments =

all: build run

build:
	cc -o $(executable) $(file) -Wno-error

run: build
	./$(executable) $(arguments)

.PHONY: all build run
