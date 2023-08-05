// this is to find the maximum of the i*a[i]
//  so in this we are only rotating the
// M4 as using remainder of the lement less than x
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
void rotate(int *p, int n, int d);
int gcd(int d, int n);
void sort(int *A, int n);
void pairsum(int *p, int n);
int main()
{
    int n, d, a[20], m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    pairsum(a, n);
    return 0;
}
void rotate(int *p, int n, int d)
{
    d = d % n;
    int temp, k = 0, j = 0, l;
    l = gcd(d, n);
    for (int i = k; i < l; i++)
    {
        temp = p[i];
        j = i;
        while (1)
        {
            k = j + d;
            if (k >= n)
                k = k - n;
            if (k == i)
                break;
            p[j] = p[k];
            j = k;
        }
        p[j] = temp;
    }
}
int gcd(int d, int n)
{
    if (n > d)
    {
        return gcd(n, d);
    }
    if (n == 0)
    {
        return d;
    }
    else
    {
        return gcd(n, d % n);
    }
}
void sort(int *A, int n)
{
    int temp, j = 0;
    for (int i = 1; i < n; i++)
    {
        temp = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > temp)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = temp;
    }
}
void pairsum(int *p, int n)
{
    int max, j = 0, sum = 0;
    max = p[0];
    for (int i = 0; i < n; i++)
    {
        if (p[i] > max)
        {
            max = p[i];
            j = i;
        }
    }
    rotate(&p[0], n, j + 1);
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", p[i]);
    }
    for (int i = 0; i < n; i++)
    {
        sum += p[i] * i;
    }
    printf("\nsum is : %d", sum);
}