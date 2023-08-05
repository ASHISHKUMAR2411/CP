#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[n], h[n], ans[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &a[i], &h[i]);
    }

    // initialize answer array with -1
    for (int i = 0; i < n; i++)
    {
        ans[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        int right_most = -1;
        for (int j = i + 1; j < n; j++)
        {
            if (h[j] < h[i])
            {
                right_most = j;
            }
        }
        ans[i] = right_most;
    }

    for (int i = 0; i < n; i++)
    {
        int j = ans[i];
        if (j == -1)
        {
            printf("-1 ");
        }
        else
        {
            printf("%d ", j + 1);
        }
    }
    printf("\n");

    return 0;
}
