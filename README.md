# Basic benchmarks in C

This is a collection of benchmarks for such simple functions as adding
1 to a number and comparing two different numbers.

The main purpose is to get a sense of how fast different commands are run
compared to each other. For example, on my machine float division is twice as
fast as integer or double division.

Inspiration was largely due to [The Practice of Programming][1] book by Brian
W. Kernighan and Rob Pike.

[1]: https://en.wikipedia.org/wiki/The_Practice_of_Programming

# How to run

Compiling a program requires a C compiler such as GCC, Clang or a similar one.

If you have a `make` program installed, you can issue the command

```
make
```

and it will run the program, record the results to `results` file and
make the cleaning for you.

If you don't have a `make` program, you can issue

```
cc -o benchmarks benchmarks.c    # assuming your compiler program is cc
./benchmarks                     # run the program
rm -rf benchmarks tmp_benchmark  # clean afterwards
```

You will be able to see results in your console and also look at them
later in the `results` file.

Note: one run of a program may take ~30 minutes.

# Configuration

You can look at file `config.h` and adjust it to your needs, then recompile the
program and run.

By default the program runs in interactive mode, you can disable it by setting
the `FLAG_INTERACTIVE` constant to 0; this way it won't ask any questions during
its run.

# Communication

Feel free to ask questions and propose things in Issues.

# License

This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or distribute
this software, either in source code form or as a compiled binary, for any
purpose, commercial or non-commercial, and by any means.

See the LICENSE file for more details.
