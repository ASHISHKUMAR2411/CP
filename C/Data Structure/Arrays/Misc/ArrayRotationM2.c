// this is for the seci=onf method for the rotation of the array
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void rotate(int *p, int n, int d);
int gcd(int d, int n);
int main()
{
    int n, d, a[20];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("\n enter the number of rotation you want  ");
    scanf("%d", &d);
    rotate(a, n, d);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
void rotate(int *p, int n, int d)
{
    d = d % n;
    int temp, k = 0, j = 0, l;
    l = gcd(d, n);
    for (int i = 0; i < l; i++)
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