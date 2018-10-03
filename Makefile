FILE.c     = benchmarks.c
EXECUTABLE = benchmarks
LOG_FILE   = results

CC = cc

all: build run clean

build:
	${CC} -o ${EXECUTABLE} ${FILE.c}

run: build
	./${EXECUTABLE}
	@echo "Results are also saved in '${LOG_FILE}'"

DEBRIS = tmp_benchmark

clean:
	rm -rf ${EXECUTABLE} ${DEBRIS}

.PHONY: all build run clean
