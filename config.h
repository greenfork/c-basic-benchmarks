#ifndef BENCHMARKS_CONFIG_H
#define BENCHMARKS_CONFIG_H

/* In order to measure fast operations, they must be run multiple times. */
unsigned long long int iterations = 1000000000;
/* Whether to run benchmarks which take 1GB of space to run */
short flag_gb_of_space = 0;

enum Flag {
    /* Whether to run in interactive mode */
    FLAG_INTERACTIVE              = 1,
    /* Flags to choose to run different benchmarks */
    FLAG_INTEGERS                 = 1,
    FLAG_FLOATS                   = 1,
    FLAG_DOUBLES                  = 1,
    FLAG_CONVERSIONS              = 1,
    FLAG_ARRAY_INDEXING           = 1,
    FLAG_CONTROL_STRUCTURES       = 1,
    FLAG_FUNCTION_DISPATCH        = 1,
    FLAG_INPUT_OUTPUT             = 1,
    FLAG_MALLOC_FREE              = 1,
    FLAG_STRING_FUNCTIONS         = 1,
    FLAG_STRING_NUMBER_CONVERSION = 1,
    /* See debug output? */
    DEBUG                         = 1,
};

#endif /* BENCHMARKS_CONFIG_H */
