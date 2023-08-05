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
    
}