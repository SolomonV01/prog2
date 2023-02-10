#include<stdio.h>
#include<stdlib.h>
#include "notesw2p2.c"

int *create_array(const int n) 
{
    //
    int *x = (int *) calloc(sizeof(int), n);
    //gives us memory
    //use free(x); if using malloc
    int *a = (int *) malloc(sizeof(int) * n);
    //
    int *z = realloc(a, (sizeof(int) * n) * 2);
    if (a == NULL) 
    {
        exit(1);
    }
    return a;
}

int mai(void) 
{
    int * x = create_array(10);

    for(int i = 0; i < 10; i++) 
    {
        printf("%d\n", x[i]);
    }

    //memory is given back
    //could cause memory leak and your computer can crash and it can cause problems
    //double free is undefined behavior
    ///compilers cannot understand it as a final call and it will break. There is no telling what will happen.
    free(x);

    return 0;
}