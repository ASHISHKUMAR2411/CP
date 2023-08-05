//in order to find the count of the roataion we have to find the index of the element of the smallest element
//  this is for counting the number of rotation a sorted array has
#include <stdio.h>
#include <stdlib.h>
// #include<string.h>
// #include<stdbool.h>
// void rotate(int *p,int n,int d);
// int gcd(int d,int n);
int count(int *p, int l, int h);
// void sort(int *A,int n);
int main()
{
    int n, d, a[20], m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    // sort(a,n);
    // printf("\n enter the rotated array : ");
    // scanf("%d",&d);
    // rotate(a,n,d);
    m = count(a, 0, n - 1);
    printf("\n number of rotation is : %d", m);
    return 0;
}
// void rotate(int *p,int n,int d)
// {
//     d=d%n;
//     int temp,k=0,j=0, l;
//     l=gcd(d,n);
//     for(int i=k;i<l;i++)
//     {
//           temp=p[i];
//           j=i;
//           while(1)
//           {
//               k=j+d;
//               if(k>=n)
//               k=k-n;
//               if(k==i)
//               break;
//               p[j]=p[k];
//               j=k;
//           }
//           p[j]=temp;
//     }
// }
// int gcd(int d,int n)
// {
//     if(n>d)
//     {
//         return gcd(n,d);
//     }
//     if(n==0)
//     {
//         return d;
//     }
//     else
//     {
//         return gcd(n,d%n);
//     }
// }
int count(int *p, int l, int h)
{
    if (l > h)
        return 0;
    if (l == h)
        return l;
    int mid = (l + h) / 2;
    if (mid < h && p[mid + 1] < p[mid])
        return (mid+1);
    if(mid>l && p[mid]<p[mid-1])
        return mid;
    if (p[h] > p[mid])
        return count(p, l, mid - 1);

    return count(p, mid + 1, h);
}
// void sort(int *A,int n)
// {
//     int temp,j=0;
//     for(int i=1;i<n;i++)
//     {
//         temp=A[i];
//         j=i-1;
//         while(j>=0&&A[j]>temp)
//         {
//             A[j+1]=A[j];
//             j--;
//         }
//         A[j+1]=temp;
//     }
// }