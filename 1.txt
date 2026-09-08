#include <stdio.h>

int main(void)
{
    int a[10] = { 5, 3, 8, 1, 9, 2, 7, 4, 6, 0 };
    int max = a[0], min = a[0];
    int i;

    for (i = 1; i < 10; i++)
    {
        if (a[i] > max) max = a[i];
        if (a[i] < min) min = a[i];
    }

    printf("Massiv: ");
    for (i = 0; i < 10; i++) printf("%d ", a[i]);
    printf("\n");

    printf("Max element: %d\n", max);
    printf("Min element: %d\n", min);
    printf("Difference: %d\n", max - min);

    return 0;
}
