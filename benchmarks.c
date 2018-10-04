#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

/* In order to measure fast operations, they must be run multiple times. */
unsigned long long int iterations = 1000000000;

/* Variables used as benchmarking data */
static unsigned long long int i;
static int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
static const int idx = 4;
static int while_cnt = -8;
static char filename[] = "tmp_benchmark";
static FILE *f;
static char buf[256];
static unsigned int i1, i2, i3;
static float f1, f2, f3;
static double d1, d2, d3;
static clock_t start, end; /* used to measure time */
static int c;

/* Flags to choose to run different benchmarks */
static short flag_integers = 1;
static short flag_floats = 1;
static short flag_doubles = 1;
static short flag_conversions = 1;
static short flag_array_indexing = 1;
static short flag_control_structures = 1;
static short flag_function_dispatch = 1;
static short flag_input_output = 1;
static short flag_malloc_free = 1;
static short flag_string_functions = 1;
static short flag_string_number_conversion = 1;
static short flag_gb_of_space = 0;

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
static char log_file[] = "results"; /* name of the file to save logs to */
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

    /* Whether to run benchmarks which take 1GB of space */
    printf("\nDo you have 1 gigabyte of space? ");
    printf("Some extra benchmarks will be run in this case.\n");
    printf("Type y to activate those benchmarks ");
    printf("or press enter for default [default no]: ");
    if ((c = getchar()) == 'y')
        flag_gb_of_space = 1;

    /* Adjust the number of iterations */
    printf("\nWould you like to adjust the number of iterations ");
    printf("per each benchmark?\n");
    printf("Benchmarks on fast operations should be run multiple times.\n");
    printf("If the current value runs too long or too fast, adjust its value.\n");
    printf("Enter the number of iterations or press enter for default\n");
    printf("[default %lld]: ", iterations);
    unsigned long long int tmp_iterations;
    if (scanf("%lld", &tmp_iterations) == 1)
        iterations = tmp_iterations;

    /* Start of the benchmark */

    if (flag_integers)                  integers();
    if (flag_floats)                    floats();
    if (flag_doubles)                   doubles();
    if (flag_conversions)               conversions();
    if (flag_array_indexing)            array_indexing();
    if (flag_control_structures)        control_structures();
    if (flag_function_dispatch)         function_dispatch();
    if (flag_input_output)              input_output();
    if (flag_malloc_free)               malloc_free();
    if (flag_string_functions)          string_functions();
    if (flag_string_number_conversion)  string_number_conversion();

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

    start = clock();
    for (i = 0; i < iterations; i++)
        i1++;
    end = clock();
    print("i1++", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        i1 = i2;
    end = clock();
    print("i1 = i2", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        i1 = i2 + i3;
    end = clock();
    print("i1 = i2 + i3", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        i1 = i2 - i3;
    end = clock();
    print("i1 = i2 - i3", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        i1 = i2 * i3;
    end = clock();
    print("i1 = i2 * i3", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        i1 = i2 / i3;
    end = clock();
    print("i1 = i2 / i3", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        i1 = i2 % i3;
    end = clock();
    print("i1 = i2 % i3", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        i1 < i2;
    end = clock();
    print("i1 < i2", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        i1 > i2;
    end = clock();
    print("i1 > i2", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        i1 <= i2;
    end = clock();
    print("i1 <= i2", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        i1 >= i2;
    end = clock();
    print("i1 >= i2", f_log);
}

void
floats(void)
{
    print_header("\nFloats:\n\n", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        f1++;
    end = clock();
    print("f1++", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        f1 = f2;
    end = clock();
    print("f1 = f2", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        f1 = f2 + f3;
    end = clock();
    print("f1 = f2 + f3", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        f1 = f2 - f3;
    end = clock();
    print("f1 = f2 - f3", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        f1 = f2 * f3;
    end = clock();
    print("f1 = f2 * f3", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        f1 = f2 / f3;
    end = clock();
    print("f1 = f2 / f3", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        f1 < f2;
    end = clock();
    print("f1 < f2", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        f1 > f2;
    end = clock();
    print("f1 > f2", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        f1 <= f2;
    end = clock();
    print("f1 <= f2", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        f1 >= f2;
    end = clock();
    print("f1 >= f2", f_log);
}

void
doubles(void)
{
    print_header("\nDoubles:\n\n", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        d1++;
    end = clock();
    print("d1++", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        d1 = d2;
    end = clock();
    print("d1 = d2", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        d1 = d2 + d3;
    end = clock();
    print("d1 = d2 + d3", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        d1 = d2 - d3;
    end = clock();
    print("d1 = d2 - d3", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        d1 = d2 * d3;
    end = clock();
    print("d1 = d2 * d3", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        d1 = d2 / d3;
    end = clock();
    print("d1 = d2 / d3", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        d1 < d2;
    end = clock();
    print("d1 < d2", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        d1 > d2;
    end = clock();
    print("d1 > d2", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        d1 <= d2;
    end = clock();
    print("d1 <= d2", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        d1 >= d2;
    end = clock();
    print("d1 >= d2", f_log);
}

void
conversions(void)
{
    print_header("\nConversions:\n\n", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        i1 = (int)f1;
    end = clock();
    print("i1 = (int)f1", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        i1 = (int)d1;
    end = clock();
    print("i1 = (int)d1", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        f1 = (float)i1;
    end = clock();
    print("f1 = (float)i1", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        f1 = (float)d1;
    end = clock();
    print("f1 = (float)d1", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        d1 = (double)i1;
    end = clock();
    print("d1 = (double)i1", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        d1 = (double)f1;
    end = clock();
    print("d1 = (double)f1", f_log);
}

void
array_indexing(void)
{
    print_header("\nArray indexing and assignment:\n\n", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        arr[idx] = idx;
    end = clock();
    print("arr[index] = index", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        arr[arr[idx]] = idx;
    end = clock();
    print("arr[arr[index]] = index", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        arr[arr[arr[idx]]] = idx;
    end = clock();
    print("arr[arr[arr[index]]] = index", f_log);
}

void
control_structures(void)
{
    print_header("\nControl structures:\n\n", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        if (i == 5) i1++;
    end = clock();
    print("if (i == 5) i1++", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        if (i != 5) i1++;
    end = clock();
    print("if (i != 5) i1++", f_log);

    start = clock();
    for (i = 0; i < iterations; i++) {
        while (while_cnt < 0) while_cnt++;
        while_cnt = -4;
    }
    end = clock();
    print("while (while_cnt < 0) i++", f_log);
}

void
function_dispatch(void)
{
    print_header("\nFunction dispatch:\n\n", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        i1 = sum1(i1);
    end = clock();
    print("i1 = sum1(i1)", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        i1 = sum2(i1, i2);
    end = clock();
    print("i1 = sum2(i1, i2)", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        i1 = sum3(i1, i2, i3);
    end = clock();
    print("i1 = sum3(i1, i2, i3)", f_log);
}

void
input_output(void)
{
    print_header("\nInput/Output:\n\n", f_log);

    if (flag_gb_of_space) {
        f = fopen(filename, "w");
        start = clock();
        for (i = 0; i < iterations; i++)
            fputs("12345", f);
        end = clock();
        fclose(f);
        print("fputs(\"12345\", f);", f_log);
    } else {
        f = fopen(filename, "w");
        fputs("qwertyiiop[asdfghj;zxc]", f);
        fclose(f);
    }

    f = fopen(filename, "r");
    start = clock();
    for (i = 0; i < iterations; i++)
        fgets(buf, 9, f);
    end = clock();
    fclose(f);
    print("fgets(buf, 9, f)", f_log);

    if (flag_gb_of_space) {
        start = clock();
        f = fopen(filename, "w");
        for (i = 0; i < iterations; i++)
            fprintf(f, "%d\n", 15);
        end = clock();
        fclose(f);
        print("fprintf(f, \"%d\", 15);", f_log);
    } else {
        f = fopen(filename, "w");
        fputs("1111111111111155555555555555555111111111111", f);
        fclose(f);
    }

    f = fopen(filename, "r");
    start = clock();
    for (i = 0; i < iterations; i++)
        fscanf(f, "%d", &i1);
    end = clock();
    fclose(f);
    print("fscanf(f, \"%d\", &i1)", f_log);
}

void
malloc_free(void)
{
    print_header("\nMalloc and free:\n\n", f_log);
    print_header("warning: this is not a regular use of the functions\n\n", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        free(malloc(8));
    end = clock();
    print("free(malloc(8))", f_log);
}

void
string_functions(void)
{
    print_header("\nString functions:\n\n", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        strncpy(buf, "01233456789", 256);
    end = clock();
    print("strncpy(buf, \"01233456789\", 256)", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        i1 = strcmp(buf, buf);
    end = clock();
    print("i1 = strcmp(buf, buf)", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        i1 = strcmp(buf, "a123456789");
    end = clock();
    print("i1 = strcmp(buf, \"a123456789\")", f_log);
}

void
string_number_conversion(void)
{
    print_header("\nString/number conversion:\n\n", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        i1 = atoi("12345");
    end = clock();
    print("i1 = atoi(\"12345\")", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        sscanf("12345", "%d", &i1);
    end = clock();
    print("sscanf(\"12345\", \"%d\", &i1)", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        snprintf(buf, 256, "%d", i1);
    end = clock();
    print("snprintf(buf, 256, \"%d\", i1)", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        f1 = atof("123.45");
    end = clock();
    print("f1 = atof(\"123.45\")", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        sscanf("123.45", "%f", &f1);
    end = clock();
    print("sscanf(\"123.45\", \"%f\", &f1)", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        snprintf(buf, 256, "%8.0f", f1);
    end = clock();
    print("snprintf(buf, 256, \"%8.0f\", f1)", f_log);
}
