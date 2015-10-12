#include <stdio.h>

struct complex {
    double real;
    double imag;
};

struct complex input_complex();

struct complex complex_add(struct complex c1, struct complex c2);
struct complex complex_mul(struct complex c1, struct complex c2);

int main()
{
    struct complex a;
    struct complex b;
    struct complex sum;
    struct complex mul;

    printf("복소수1 실수부 허수부 입력: ");
    a = input_complex();

    printf("복소수2 실수부 허수부 입력: ");
    b = input_complex();

    sum = complex_add(a, b);
    printf("(%lf+%lfi) + (%lf+%lfi) = %lf+%lfi\n",
        a.real, a.imag, b.real, b.imag, sum.real, sum.imag);

    mul = complex_mul(a, b);
    printf("(%lf+%lfi) * (%lf+%lfi) = %lf+%lfi\n",
        a.real, a.imag, b.real, b.imag, mul.real, mul.imag);

    return 0;
}

struct complex input_complex()
{
    struct complex c;
    scanf("%lf %lf", &(c.real), &(c.imag));

    return c;
}

struct complex complex_add(struct complex c1, struct complex c2)
{
    struct complex sum;
    sum.real = c1.real + c2.real;
    sum.imag = c1.imag + c2.imag;
    
    return sum;
}

struct complex complex_mul(struct complex c1, struct complex c2)
{
    struct complex mul;
    mul.real = (c1.real * c2.real) - (c1.imag * c2.imag);
    mul.imag = (c1.imag * c2.real) + (c1.real * c2.imag);

    return mul;
}
