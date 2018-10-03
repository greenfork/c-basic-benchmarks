#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int sum1(int);
int sum2(int, int);
int sum3(int, int, int);

int
main()
{
    clock_t start, end;
    unsigned long long int iterations = 1000000000;
    unsigned long long int register i;
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int index = 4;
    int while_cnt = -8;
    char filename[] = "tmp_benchmark";
    FILE *f;
    char buf[256];

    unsigned int i1 = (int)rand(), i2 = (int)rand(), i3 = (int)rand();
    float  f1 = (float)rand(), f2 = (float)rand(), f3 = (float)rand();
    double d1 = (double)rand(), d2 = (double)rand(), d3 = (double)rand();

    printf("\nIntegers:\n\n");

    start = clock();
    for (i = 0; i < iterations; i++)
        i1++;
    end = clock();
    printf("%50s\t", "i1++");
    printf("%6.2lf\n", difftime(end, start));

    start = clock();
    for (i = 0; i < iterations; i++)
        i1 = i2;
    end = clock();
    printf("%50s\t", "i1 = i2");
    printf("%6.2lf\n", difftime(end, start));

    start = clock();
    for (i = 0; i < iterations; i++)
        i1 = i2 + i3;
    end = clock();
    printf("%50s\t", "i1 = i2 + i3");
    printf("%6.2lf\n", difftime(end, start));

    start = clock();
    for (i = 0; i < iterations; i++)
        i1 = i2 - i3;
    end = clock();
    printf("%50s\t", "i1 = i2 - i3");
    printf("%6.2lf\n", difftime(end, start));

    start = clock();
    for (i = 0; i < iterations; i++)
        i1 = i2 * i3;
    end = clock();
    printf("%50s\t", "i1 = i2 * i3");
    printf("%6.2lf\n", difftime(end, start));

    start = clock();
    for (i = 0; i < iterations; i++)
        i1 = i2 / i3;
    end = clock();
    printf("%50s\t", "i1 = i2 / i3");
    printf("%6.2lf\n", difftime(end, start));

    start = clock();
    for (i = 0; i < iterations; i++)
        i1 = i2 % i3;
    end = clock();
    printf("%50s\t", "i1 = i2 % i3");
    printf("%6.2lf\n", difftime(end, start));

    start = clock();
    for (i = 0; i < iterations; i++)
        i1 < i2;
    end = clock();
    printf("%50s\t", "i1 < i2");
    printf("%6.2lf\n", difftime(end, start));

    start = clock();
    for (i = 0; i < iterations; i++)
        i1 > i2;
    end = clock();
    printf("%50s\t", "i1 > i2");
    printf("%6.2lf\n", difftime(end, start));

    start = clock();
    for (i = 0; i < iterations; i++)
        i1 <= i2;
    end = clock();
    printf("%50s\t", "i1 <= i2");
    printf("%6.2lf\n", difftime(end, start));

    start = clock();
    for (i = 0; i < iterations; i++)
        i1 >= i2;
    end = clock();
    printf("%50s\t", "i1 >= i2");
    printf("%6.2lf\n", difftime(end, start));


    printf("\nFloats:\n\n");

    start = clock();
    for (i = 0; i < iterations; i++)
        f1++;
    end = clock();
    printf("%50s\t", "f1++");
    printf("%6.2lf\n", difftime(end, start));

    start = clock();
    for (i = 0; i < iterations; i++)
        f1 = f2;
    end = clock();
    printf("%50s\t", "f1 = f2");
    printf("%6.2lf\n", difftime(end, start));

    start = clock();
    for (i = 0; i < iterations; i++)
        f1 = f2 + f3;
    end = clock();
    printf("%50s\t", "f1 = f2 + f3");
    printf("%6.2lf\n", difftime(end, start));

    start = clock();
    for (i = 0; i < iterations; i++)
        f1 = f2 - f3;
    end = clock();
    printf("%50s\t", "f1 = f2 - f3");
    printf("%6.2lf\n", difftime(end, start));

    start = clock();
    for (i = 0; i < iterations; i++)
        f1 = f2 * f3;
    end = clock();
    printf("%50s\t", "f1 = f2 * f3");
    printf("%6.2lf\n", difftime(end, start));

    start = clock();
    for (i = 0; i < iterations; i++)
        f1 = f2 / f3;
    end = clock();
    printf("%50s\t", "f1 = f2 / f3");
    printf("%6.2lf\n", difftime(end, start));

    start = clock();
    for (i = 0; i < iterations; i++)
        f1 < f2;
    end = clock();
    printf("%50s\t", "f1 < f2");
    printf("%6.2lf\n", difftime(end, start));

    start = clock();
    for (i = 0; i < iterations; i++)
        f1 > f2;
    end = clock();
    printf("%50s\t", "f1 > f2");
    printf("%6.2lf\n", difftime(end, start));

    start = clock();
    for (i = 0; i < iterations; i++)
        f1 <= f2;
    end = clock();
    printf("%50s\t", "f1 <= f2");
    printf("%6.2lf\n", difftime(end, start));

    start = clock();
    for (i = 0; i < iterations; i++)
        f1 >= f2;
    end = clock();
    printf("%50s\t", "f1 >= f2");
    printf("%6.2lf\n", difftime(end, start));


printf("\nDoubles:\n\n");

    start = clock();
    for (i = 0; i < iterations; i++)
        d1++;
    end = clock();
    printf("%50s\t", "d1++");
    printf("%6.2lf\n", difftime(end, start));

    start = clock();
    for (i = 0; i < iterations; i++)
        d1 = d2;
    end = clock();
    printf("%50s\t", "d1 = d2");
    printf("%6.2lf\n", difftime(end, start));

    start = clock();
    for (i = 0; i < iterations; i++)
        d1 = d2 + d3;
    end = clock();
    printf("%50s\t", "d1 = d2 + d3");
    printf("%6.2lf\n", difftime(end, start));

    start = clock();
    for (i = 0; i < iterations; i++)
        d1 = d2 - d3;
    end = clock();
    printf("%50s\t", "d1 = d2 - d3");
    printf("%6.2lf\n", difftime(end, start));

    start = clock();
    for (i = 0; i < iterations; i++)
        d1 = d2 * d3;
    end = clock();
    printf("%50s\t", "d1 = d2 * d3");
    printf("%6.2lf\n", difftime(end, start));

    start = clock();
    for (i = 0; i < iterations; i++)
        d1 = d2 / d3;
    end = clock();
    printf("%50s\t", "d1 = d2 / d3");
    printf("%6.2lf\n", difftime(end, start));

    start = clock();
    for (i = 0; i < iterations; i++)
        d1 < d2;
    end = clock();
    printf("%50s\t", "d1 < d2");
    printf("%6.2lf\n", difftime(end, start));

    start = clock();
    for (i = 0; i < iterations; i++)
        d1 > d2;
    end = clock();
    printf("%50s\t", "d1 > d2");
    printf("%6.2lf\n", difftime(end, start));

    start = clock();
    for (i = 0; i < iterations; i++)
        d1 <= d2;
    end = clock();
    printf("%50s\t", "d1 <= d2");
    printf("%6.2lf\n", difftime(end, start));

    start = clock();
    for (i = 0; i < iterations; i++)
        d1 >= d2;
    end = clock();
    printf("%50s\t", "d1 >= d2");
    printf("%6.2lf\n", difftime(end, start));

    printf("\nConversions:\n\n");

    start = clock();
    for (i = 0; i < iterations; i++)
        i1 = (int)f1;
    end = clock();
    printf("%50s\t", "i1 = (int)f1");
    printf("%6.2lf\n", difftime(end, start));

    start = clock();
    for (i = 0; i < iterations; i++)
        i1 = (int)d1;
    end = clock();
    printf("%50s\t", "i1 = (int)d1");
    printf("%6.2lf\n", difftime(end, start));

    start = clock();
    for (i = 0; i < iterations; i++)
        f1 = (float)i1;
    end = clock();
    printf("%50s\t", "f1 = (float)i1");
    printf("%6.2lf\n", difftime(end, start));

    start = clock();
    for (i = 0; i < iterations; i++)
        f1 = (float)d1;
    end = clock();
    printf("%50s\t", "f1 = (float)d1");
    printf("%6.2lf\n", difftime(end, start));

    start = clock();
    for (i = 0; i < iterations; i++)
        d1 = (double)i1;
    end = clock();
    printf("%50s\t", "d1 = (double)i1");
    printf("%6.2lf\n", difftime(end, start));

    start = clock();
    for (i = 0; i < iterations; i++)
        d1 = (double)f1;
    end = clock();
    printf("%50s\t", "d1 = (double)f1");
    printf("%6.2lf\n", difftime(end, start));

    printf("\nArray indexing and assignment:\n\n");

    start = clock();
    for (i = 0; i < iterations; i++)
        arr[index] = i1;
    end = clock();
    printf("%50s\t", "arr[index] = i1");
    printf("%6.2lf\n", difftime(end, start));

    start = clock();
    for (i = 0; i < iterations; i++)
        arr[arr[index]] = i1;
    end = clock();
    printf("%50s\t", "arr[arr[index]] = i1");
    printf("%6.2lf\n", difftime(end, start));

    start = clock();
    for (i = 0; i < iterations; i++)
        arr[arr[arr[index]]] = i1;
    end = clock();
    printf("%50s\t", "arr[arr[arr[index]]] = i1");
    printf("%6.2lf\n", difftime(end, start));

    printf("\nControl structures:\n\n");

    start = clock();
    for (i = 0; i < iterations; i++)
        if (i == 5) i1++;
    end = clock();
    printf("%50s\t", "if (i == 5) i1++");
    printf("%6.2lf\n", difftime(end, start));

    start = clock();
    for (i = 0; i < iterations; i++)
        if (i != 5) i1++;
    end = clock();
    printf("%50s\t", "if (i != 5) i1++");
    printf("%6.2lf\n", difftime(end, start));

    start = clock();
    for (i = 0; i < iterations; i++) {
        while (while_cnt < 0) while_cnt++;
        while_cnt = -4;
    }
    end = clock();
    printf("%50s\t", "while (while_cnt < 0) i++");
    printf("%8.0lf\n", difftime(end, start));

    printf("\nFunction dispatch\n\n");

    start = clock();
    for (i = 0; i < iterations; i++)
        i1 = sum1(i1);
    end = clock();
    printf("%50s\t", "i1 = sum1(i1)");
    printf("%8.0lf\n", difftime(end, start));

    start = clock();
    for (i = 0; i < iterations; i++)
        i1 = sum2(i1, i2);
    end = clock();
    printf("%50s\t", "i1 = sum2(i1, i2)");
    printf("%8.0lf\n", difftime(end, start));

    start = clock();
    for (i = 0; i < iterations; i++)
        i1 = sum3(i1, i2, i3);
    end = clock();
    printf("%50s\t", "i1 = sum3(i1, i2, 3)");
    printf("%8.0lf\n", difftime(end, start));

    printf("\nInput/Output:\n\n");

    f = fopen(filename, "w+");

    start = clock();
    for (i = 0; i < iterations; i++)
        fputs(filename, f);
    end = clock();
    printf("%50s\t", "fputs(filename, f)");
    printf("%8.0lf\n", difftime(end, start));

    start = clock();
    for (i = 0; i < iterations; i++)
        fgets(filename, 9, f);
    end = clock();
    printf("%50s\t", "fgets(filename, 9, f)");
    printf("%8.0lf\n", difftime(end, start));

    start = clock();
    for (i = 0; i < iterations; i++)
        fprintf(f, "%d\n", i1);
    end = clock();
    printf("%50s\t", "fprintf(f, \"%%d\n\", i1)");
    printf("%8.0lf\n", difftime(end, start));

    start = clock();
    for (i = 0; i < iterations; i++)
        fscanf(f, "%d", &i1);
    end = clock();
    printf("%50s\t", "fscanf(f, \"%%d\", &i1)");
    printf("%8.0lf\n", difftime(end, start));

    fclose(f);

    printf("\nMalloc and free:\n\n");
    printf("warning: this is not a regular use of the functions\n\n");

    start = clock();
    for (i = 0; i < iterations; i++)
        free(malloc(8));
    end = clock();
    printf("%50s\t", "free(malloc(8))");
    printf("%8.0lf\n", difftime(end, start));

    printf("\nString functions:\n\n");

    start = clock();
    for (i = 0; i < iterations; i++)
        strncpy(buf, "01233456789", 256);
    end = clock();
    printf("%50s\t", "strncpy(buf, \"01233456789\", 256)");
    printf("%8.0lf\n", difftime(end, start));

    start = clock();
    for (i = 0; i < iterations; i++)
        i1 = strcmp(buf, buf);
    end = clock();
    printf("%50s\t", "i1 = strcmp(buf, buf)");
    printf("%8.0lf\n", difftime(end, start));

    start = clock();
    for (i = 0; i < iterations; i++)
        i1 = strcmp(buf, "a123456789");
    end = clock();
    printf("%50s\t", "i1 = strcmp(buf, \"a123456789\")");
    printf("%8.0lf\n", difftime(end, start));

    printf("\nString/number conversion:\n\n");

    start = clock();
    for (i = 0; i < iterations; i++)
        i1 = atoi("12345");
    end = clock();
    printf("%50s\t", "i1 = atoi(\"12345\")");
    printf("%8.0lf\n", difftime(end, start));

    start = clock();
    for (i = 0; i < iterations; i++)
        sscanf("12345", "%d", &i1);
    end = clock();
    printf("%50s\t", "sscanf(\"12345\", \"%%d\", &i1)");
    printf("%8.0lf\n", difftime(end, start));

    start = clock();
    for (i = 0; i < iterations; i++)
        snprintf(buf, 256, "%d", i1);
    end = clock();
    printf("%50s\t", "snprintf(buf, 256, \"%%d\", i1)");
    printf("%8.0lf\n", difftime(end, start));

    start = clock();
    for (i = 0; i < iterations; i++)
        f1 = atof("123.45");
    end = clock();
    printf("%50s\t", "f1 = atof(\"123.45\")");
    printf("%8.0lf\n", difftime(end, start));

    start = clock();
    for (i = 0; i < iterations; i++)
        sscanf("123.45", "%f", &f1);
    end = clock();
    printf("%50s\t", "sscanf(\"123.45\", \"%%f\", &f1)");
    printf("%8.0lf\n", difftime(end, start));

    start = clock();
    for (i = 0; i < iterations; i++)
        snprintf(buf, 256, "%8.0f", f1);
    end = clock();
    printf("%50s\t", "snprintf(buf, 256, \"%%8.0f\", f1)");
    printf("%8.0lf\n", difftime(end, start));

    return 0;
}

int
sum1(int a)
{
    return a;
}

int sum2(int a, int b)
{
    return a + b;
}

int sum3(int a, int b, int c)
{
    return a + b + c;
}
