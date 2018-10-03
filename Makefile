FILE.c = benchmarks.c
EXECUTABLE = benchmarks

all: build run

build:
	cc -o ${EXECUTABLE} ${FILE.c}

run: build
	./${EXECUTABLE}

DEBRIS = tmp_benchmark

clean:
	rm -rf ${EXECUTABLE} ${DEBRIS}

.PHONY: all build run clean
