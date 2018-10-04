#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"

#define LOOP(expr) {                            \
        start = clock();                        \
        for (i = 0; i < iterations; i++)        \
            expr;                               \
        end = clock();                          \
        print(#expr, f_log);                    \
    }

extern unsigned long long int iterations;
extern short flag_gb_of_space;

/* Variables used as benchmarking data */
static unsigned long long int i;
static int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
static const int idx = 4;
static int while_cnt = -8;
static const char filename[] = "tmp_benchmark";
static FILE *f;
static char buf[256];
static unsigned int i1, i2, i3;
static float f1, f2, f3;
static double d1, d2, d3;
static clock_t start, end; /* used to measure time */
static unsigned long long int tmp_iterations;

/* Functions which execute particular benchmarks */
void integers(void);
void floats(void);
void doubles(void);
void conversions(void);
void array_indexing(void);
void control_structures(void);
void function_dispatch(void);
void input_output(void);
void malloc_free(void);
void string_functions(void);
void string_number_conversion(void);

/* Functions used as benchmarking data */
int sum1(int);
int sum2(int, int);
int sum3(int, int, int);

/* Handle output to stdout and to file */
void print(char *, FILE *);
void print_header(char *, FILE *);

/* Logging variables */
extern const char log_file[];
static FILE *f_log;

/*
 * Measure common operations performed in C and compare them to each
 * other. The value showed in this benchmark measures CPU cycles and
 * does not mean the time spent in seconds though it can be seen as a
 * reflection of the actual time.
 */
int
main()
{
    i1 = (int)rand(), i2 = (int)rand(), i3 = (int)rand();
    f1 = (float)rand(), f2 = (float)rand(), f3 = (float)rand();
    d1 = (double)rand(), d2 = (double)rand(), d3 = (double)rand();
    f_log = fopen(log_file, "w");

    if (FLAG_INTERACTIVE) {
        /* Whether to run benchmarks which take 1GB of space */
        printf("\nDo you have 1 gigabyte of space? ");
        printf("Some extra benchmarks will be run in this case.\n");
        printf("Type y to activate those benchmarks ");
        printf("or press enter for default\n[default no]: ");
        fgets(buf, sizeof(buf), stdin);
        if (buf[0] == 'y')
            flag_gb_of_space = 1;

        if (DEBUG) {
            printf("\n\n*debug* flag_gb_of_space: %d\n", flag_gb_of_space);
            printf("*debug* %s\n\n", buf);
        }

        /* Adjust the number of iterations */
        printf("\nWould you like to adjust the number of iterations ");
        printf("per each benchmark?\n");
        printf("Benchmarks on fast operations should be run multiple times.\n");
        printf("If the current value runs too long or too fast, ");
        printf("adjust its value.\n");
        printf("Enter the number of iterations or press enter for default\n");
        printf("[default %lld]: ", iterations);
        fgets(buf, sizeof(buf), stdin);
        if (sscanf(buf, "%lld", &tmp_iterations) == 1)
            iterations = tmp_iterations;

        if (DEBUG) {
            printf("\n\n*debug* tmp_iterations: %lld\n", tmp_iterations);
            printf("*debug* iterations: %lld\n", iterations);
            printf("*debug* %s\n\n", buf);
        }
    }

    /* Start of the benchmark */

    if (FLAG_INTEGERS)                  integers();
    if (FLAG_FLOATS)                    floats();
    if (FLAG_DOUBLES)                   doubles();
    if (FLAG_CONVERSIONS)               conversions();
    if (FLAG_ARRAY_INDEXING)            array_indexing();
    if (FLAG_CONTROL_STRUCTURES)        control_structures();
    if (FLAG_FUNCTION_DISPATCH)         function_dispatch();
    if (FLAG_INPUT_OUTPUT)              input_output();
    if (FLAG_MALLOC_FREE)               malloc_free();
    if (FLAG_STRING_FUNCTIONS)          string_functions();
    if (FLAG_STRING_NUMBER_CONVERSION)  string_number_conversion();

    fclose(f_log);

    return 0;
}

int
sum1(int a)
{
    return a;
}

int
sum2(int a, int b)
{
    return a + b;
}

int
sum3(int a, int b, int c)
{
    return a + b + c;
}

void
print(char *s, FILE *f)
{
    printf("%58s\t\t", s);
    fprintf(f, "%58s\t\t", s);
    printf("%8.0lf\n", difftime(end, start));
    fprintf(f, "%8.0lf\n", difftime(end, start));
    /* Save intermediate results in case of abort */
    fflush(f);
}

void
print_header(char *s, FILE *f)
{
    printf("%s", s);
    fprintf(f, "%s", s);
    /* Save intermediate results in case of abort */
    fflush(f);
}

void
integers(void)
{
    print_header("\nIntegers:\n\n", f_log);

    LOOP(i1++);
    LOOP(i1 = i2);
    LOOP(i1 = i2 + i3);
    LOOP(i1 = i2 - i3);
    LOOP(i1 = i2 * i3);
    LOOP(i1 = i2 / i3);
    LOOP(i1 = i2 % i3);
    LOOP(i1 < i2);
    LOOP(i1 > i2);
    LOOP(i1 <= i2);
    LOOP(i1 >= i2);
}

void
floats(void)
{
    print_header("\nFloats:\n\n", f_log);

    LOOP(f1++);
    LOOP(f1 = f2);
    LOOP(f1 = f2 + f3);
    LOOP(f1 = f2 - f3);
    LOOP(f1 = f2 * f3);
    LOOP(f1 = f2 / f3);
    LOOP(f1 < f2);
    LOOP(f1 > f2);
    LOOP(f1 <= f2);
    LOOP(f1 >= f2);
}

void
doubles(void)
{
    print_header("\nDoubles:\n\n", f_log);

    LOOP(d1++);
    LOOP(d1 = d2);
    LOOP(d1 = d2 + d3);
    LOOP(d1 = d2 - d3);
    LOOP(d1 = d2 * d3);
    LOOP(d1 = d2 / d3);
    LOOP(d1 < d2);
    LOOP(d1 > d2);
    LOOP(d1 <= d2);
    LOOP(d1 >= d2);
}

void
conversions(void)
{
    print_header("\nConversions:\n\n", f_log);

    LOOP(i1 = (int)f1);
    LOOP(i1 = (int)d1);
    LOOP(f1 = (float)i1);
    LOOP(f1 = (float)d1);
    LOOP(d1 = (double)i1);
    LOOP(d1 = (double)f1);
}

void
array_indexing(void)
{
    print_header("\nArray indexing and assignment:\n\n", f_log);

    LOOP(arr[idx] = idx);
    LOOP(arr[arr[idx]] = idx);
    LOOP(arr[arr[arr[idx]]] = idx);
}

void
control_structures(void)
{
    print_header("\nControl structures:\n\n", f_log);

    LOOP(if (i == 5) i1++);
    LOOP(if (i != 5) i1++);
    LOOP(while (while_cnt < 0) while_cnt++; while_cnt = -4);
}

void
function_dispatch(void)
{
    print_header("\nFunction dispatch:\n\n", f_log);

    LOOP(i1 = sum1(i1));
    LOOP(i1 = sum2(i1, i2));
    LOOP(i1 = sum3(i1, i2, i3));
}

void
input_output(void)
{
    print_header("\nInput/Output:\n\n", f_log);

    if (flag_gb_of_space) {
        f = fopen(filename, "w");
        LOOP(fputs("12345", f))
        fclose(f);
    } else {
        f = fopen(filename, "w");
        fputs("qwertyiiop[asdfghj;zxc]", f);
        fclose(f);
    }

    f = fopen(filename, "r");
    LOOP(fgets(buf, 9, f));
    fclose(f);

    if (flag_gb_of_space) {
        f = fopen(filename, "w");
        LOOP(fprintf(f, "%d\n", 15));
        fclose(f);
    } else {
        f = fopen(filename, "w");
        fputs("1111111111111155555555555555555111111111111", f);
        fclose(f);
    }

    f = fopen(filename, "r");
    LOOP(fscanf(f, "%d", &i1));
    fclose(f);
}

void
malloc_free(void)
{
    print_header("\nMalloc and free:\n\n", f_log);
    print_header("warning: this is not a regular use of the functions\n\n",
                 f_log);

    LOOP(free(malloc(8)));
}

void
string_functions(void)
{
    print_header("\nString functions:\n\n", f_log);

    LOOP(strncpy(buf, "01233456789", sizeof(buf)));
    LOOP(i1 = strcmp(buf, buf));
    LOOP(i1 = strcmp(buf, "a123456789"));
}

void
string_number_conversion(void)
{
    print_header("\nString/number conversion:\n\n", f_log);

    LOOP(i1 = atoi("12345"));
    LOOP(sscanf("12345", "%d", &i1));
    LOOP(snprintf(buf, sizeof(buf), "%d", i1));
    LOOP(f1 = atof("123.45"));
    LOOP(sscanf("123.45", "%f", &f1));
    LOOP(snprintf(buf, sizeof(buf), "%8.0f", f1));
}
