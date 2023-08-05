#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int *arr = (int *)malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++)
    {
        arr[i] = 5;
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", *(arr + i));
    }
}