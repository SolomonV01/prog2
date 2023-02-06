#include<stdio.h>

//find factorial
unsigned int factorial(unsigned int n)
{
    int res = 1, i;
    for (i = 2; i <= n; i++)
        res *= i;
    return res;
}

int main()
{
    int num = 5;
    printf(
        "Factorial of %d is %d", num, factorial(num));
    return 0;
}