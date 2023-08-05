#include <stdio.h>
#include <stdlib.h>
void rearrange(int *a, int n);
int main()
{
    // motive was to bring all the negative before positive.
    // int his we are using extra space but time complexity is O(n)
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    rearrange(a, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
void rearrange(int *a, int n)
{
    int temp = 0, j = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < 0)
        {
            temp = a[i];
            j = i - 1;
            while (j >= 0 && a[j] > 0)
            {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = temp;
        }
    }
}