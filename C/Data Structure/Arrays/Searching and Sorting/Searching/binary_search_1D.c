#include <stdio.h>
#include <string.h>
int bsearch(int A[], int n, int el);
int main()
{
    // search using bsearch  search in 1D array
    int A[20], n, el, m;
    printf("\n enter the number of elements you want to enter in the array : \t");
    scanf("%d", &n);
    printf("\n enter the elements of the array \n");
    for (int i = 0; i < n; i++)
    {
        printf("enter the %d elements : \t ", i + 1);
        scanf("%d", &A[i]);
    }
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n enter the element to seach \t ");
    scanf("%d", &el);
    m = bsearch(A, n, el);

    if (m == -1)
    {
        printf("\n element not  found please try again");
    }
    else
    {
        printf("\n element %d found at %d position ", el, m + 1);
    }
    return 0;
}
int bsearch(int A[], int n, int el)
{
    int b = 0, l = n - 1, mid;
    while (b < l)
    {
        mid = (b + l) / 2;
        if (A[mid] == el)
        {
            return mid;
        }
        else if (A[mid] > el)
        {
            l = mid - 1;
        }
        else
        {
            b = mid + 1;
        }
    }
    return -1;
}