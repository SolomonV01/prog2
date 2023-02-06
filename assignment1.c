#include<stdio.h>

int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int isPrime(int n)
{
    if (n <= 1)
        return 0;
    if (n == 2 || n == 3)
        return 1;
    if (n % 2 == 0 || n % 3 == 0)
        return 0;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    return 1;
}

unsigned int factorial(unsigned int n)
{
    int res = 1, i;
    for (i = 2; i <= n; i++)
        res *= i;
    return res;
}

int main()
{
    int n = 9;
    printf("%d", fib(n));
    getchar();
    return 0;

    if (isPrime(11) == 1)
        printf("true\n");
    else
        printf("false\n");
    return 0;

    int num = 5;
    printf(
        "Factorial of %d is %d", num, factorial(num));
    return 0;

}
