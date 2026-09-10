#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    char famil[20];
    char name[20];
    char facult[20];
    int Nomzach;
};

int main(void)
{
    int n = 0;
    int count = 0;
    struct student* stud = NULL;
    char buf[20];
    char searchFamil[20] = { 0 };
    int i;
    int found = 0;

    printf("Enter number students ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Error: incorrect number\n");
        return 1;
    }

    stud = (struct student*)malloc(n * sizeof(struct student));
    if (stud == NULL)
    {
        printf("Memory allocation error\n");
        return 1;
    }

    printf("Enter student inf\n");
    printf("Enter '*' to stop\n");

    for (i = 0; i < n; i++)
    {
        printf("Student %d:\n", i + 1);
        printf("  Surname: ");
        if (scanf("%19s", buf) != 1)
        {
            printf("Error\n");
            break;
        }

        if (strcmp(buf, "*") == 0)
        {
            break;
        }

        strcpy(stud[i].famil, buf);

        printf("  Name: ");
        scanf("%19s", stud[i].name);

        printf("  Faculty: ");
        scanf("%19s", stud[i].facult);

        printf("  Student ID number: ");
        scanf("%d", &stud[i].Nomzach);

        count++;
    }

    if (count < n && count > 0)
    {
        struct student* tmp = (struct student*)realloc(stud, count * sizeof(struct student));
        if (tmp != NULL)
        {
            stud = tmp;
        }
    }
    else if (count == 0)
    {
        printf("No students entered.\n");
        free(stud);
        return 0;
    }

    printf("\nSurname (or part of it) to search: ");
    if (scanf("%19s", searchFamil) != 1)
    {
        printf("Error\n");
        free(stud);
        return 1;
    }
    searchFamil[19] = '\0';

    for (i = 0; i < count; i++)
    {
        if (strstr(stud[i].famil, searchFamil) != NULL)
        {
            printf("Found student: %s %s, faculty: %s, student ID number: %d\n",
                stud[i].famil, stud[i].name, stud[i].facult, stud[i].Nomzach);
            found = 1;
        }
    }

    if (!found)
    {
        printf("No student with surname containing \"%s\" was found.\n", searchFamil);
    }

    free(stud);
    return 0;
}