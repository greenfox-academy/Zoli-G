#include <stdio.h>

typedef struct complex
{
    float real;
    float imag;
} complex;


//TODO: create 3 functions, which calculates the sum, subtraction and multiplication of a complex number.
// you can read about complex number's operations here: https://www.mathsisfun.com/numbers/complex-numbers.html
complex c_sum(complex c1, complex c2, complex *result);
complex c_subtr(complex c1, complex c2, complex *result);
complex c_mult(complex c1, complex c2, complex *result);

int main()
{
    complex n1, n2;
    n1.real = 5;
    n1.imag = 7.2;

    n2.real = 6;
    n2.imag = 8.1;

    complex result;

    printf("Complex Calculator\n\n");

    c_sum(n1, n2, &result);
    printf("Sum: n1 + n2 = %g + i x %g\n", result.real, result.imag);

    c_subtr(n1, n2, &result);
    printf("Subtraction: n1 - n2 = %g + i x %g\n", result.real, result.imag);

    c_mult(n1, n2, &result);
    printf("Multiplication: n1 x n2 = %g + i x %g\n", result.real, result.imag);

    return 0;
}

complex c_sum(complex c1, complex c2, complex *result) {

	(*result).real = c1.real + c2.real;
	(*result).imag = c1.imag + c2.imag;
}

complex c_subtr(complex c1, complex c2, complex *result) {

	(*result).real = c1.real - c2.real;
	(*result).imag = c1.imag - c2.imag;
}

complex c_mult(complex c1, complex c2, complex *result) {

	(*result).real = c1.real * c2.real - c1.imag * c2.imag;
	(*result).imag = c1.real * c2.imag + c1.imag * c2.real;
}