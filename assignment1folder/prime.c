#include<stdio.h>

//check prime
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

int main()
{
    if (isPrime(10) == 1)
        printf("Is Prime\n");
    else
        printf("Is Not Prime\n");
    return 0;
}