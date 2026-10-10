#include <stdio.h>

#define ROWS 2
#define COLS 5

int main(void)
{
    int a[ROWS][COLS] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10}
    };
    int i, j;
    int colSum[COLS] = { 0 };

    printf("Bivariate massiv:\n");
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
            printf("%3d ", a[i][j]);
        printf("\n");
    }

    for (j = 0; j < COLS; j++)
    {
        for (i = 0; i < ROWS; i++)
            colSum[j] += a[i][j];
    }

    printf("Sum by columns:\n");
    for (j = 0; j < COLS; j++)
        printf("Columns %d: %d\n", j, colSum[j]);

    return 0;
}
