#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int n = 10;
    int a[10];
    int i;

    srand(time(NULL));

    for (i = 0; i < n; i++)
        a[i] = rand() % 100;

    printf("Result:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}
