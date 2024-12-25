#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define EPS 1e-6

int main()
{
    int a = 3;
    int *A;
    A = (int*)malloc(a * sizeof(int));
    for (int i = 0; i < a; i++)
        scanf("%d", &A[i]);
    printf("A:\n");

    A = (int*)realloc(A, a + 1);
    A[3] = 20;
    for (int i = 0; i < a + 1; i++)
        printf("%d ", A[i]);
    return 0;
}