#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int sum1(int);
int sum2(int, int);
int sum3(int, int, int);
void print(char *, FILE *);
void print_header(char *, FILE *);

static clock_t start, end;

int
main()
{
    unsigned long long int iterations = 1000000000;
    unsigned long long int register i;
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int index = 4;
    int while_cnt = -8;
    char filename[] = "tmp_benchmark";
    FILE *f;
    char buf[256];

    char log_file[] = "results";
    FILE *f_log;
    f_log = fopen(log_file, "w");

    unsigned int i1 = (int)rand(), i2 = (int)rand(), i3 = (int)rand();
    float  f1 = (float)rand(), f2 = (float)rand(), f3 = (float)rand();
    double d1 = (double)rand(), d2 = (double)rand(), d3 = (double)rand();

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

    print_header("\nArray indexing and assignment:\n\n", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        arr[index] = index;
    end = clock();
    print("arr[index] = index", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        arr[arr[index]] = index;
    end = clock();
    print("arr[arr[index]] = index", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        arr[arr[arr[index]]] = index;
    end = clock();
    print("arr[arr[arr[index]]] = index", f_log);

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

    print_header("\nInput/Output:\n\n", f_log);

    start = clock();
    for (i = 0; i < iterations; i++) {
        f = fopen(filename, "w");
        fputs("12345", f);
        fclose(f);
    }
    end = clock();
    print("fopen(filename, \"w\"); fputs(\"12345\", f); fclose(f);", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        fgets(buf, 9, f);
    end = clock();
    print("fgets(buf, 9, f)", f_log);

    start = clock();
    for (i = 0; i < iterations; i++) {
        f = fopen(filename, "w");
        fprintf(f, "%d\n", 15);
        fclose(f);
    }
    end = clock();
    print("fopen(filename, \"w\"); fprintf(f, \"%d\", 15); fclose(f);", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        fscanf(f, "%d", &i1);
    end = clock();
    print("fscanf(f, \"%d\", &i1)", f_log);

    fclose(f);

    print_header("\nMalloc and free:\n\n", f_log);
    print_header("warning: this is not a regular use of the functions\n\n", f_log);

    start = clock();
    for (i = 0; i < iterations; i++)
        free(malloc(8));
    end = clock();
    print("free(malloc(8))", f_log);

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
    fprintf(f_log, buf, 256, "%d", i1);
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
    fprintf(f_log, buf, 256, "%8.0f", f1);
    end = clock();
    print("snprintf(buf, 256, \"%8.0f\", f1)", f_log);

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
}

void
print_header(char *s, FILE *f)
{
    printf("%s", s);
    fprintf(f, "%s", s);
}
