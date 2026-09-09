#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int n, i, j;
    int** a;
    int sumAboveDiag = 0;

    printf("Size: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Error size!\n");
        return 1;
    }

    a = (int**)malloc(n * sizeof(int*));
    if (a == NULL)
    {
        printf("Error memory!\n");
        return 1;
    }
    for (i = 0; i < n; i++)
    {
        a[i] = (int*)malloc(n * sizeof(int));
        if (a[i] == NULL)
        {
            printf("Error memory!\n");
            return 1;
        }
    }

    srand((unsigned int)time(NULL));

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            a[i][j] = rand() % 111 - 30;

    printf("\nThe matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%4d ", a[i][j]);
        printf("\n");
    }

    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            sumAboveDiag += a[i][j];

    printf("\nSum elements: %ld\n", sumAboveDiag);

    for (i = 0; i < n; i++)
        free(a[i]);
    free(a);

    return 0;
}