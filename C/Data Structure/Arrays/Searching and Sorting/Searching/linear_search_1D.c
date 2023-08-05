#include<stdio.h>
#include<string.h>
int Lsearch( int A[], int n,int el);
int main()
{
    // search using linear  search in 1D array
    int A[20],n,el,m;
    printf("\n enter the number of elements you want to enter in the array : \t");
    scanf("%d",&n);
    printf("\n enter the elements of the array \n");
    for(int i=0;i<n;i++)
    {
        printf("enter the %d elements : \t ",i+1);
        scanf("%d",&A[i]);
    }
    printf("\n enter the element to seach \t ");
    scanf("%d",&el);
    m=Lsearch(A,n,el);
    
    if(m==-1)
    {
        printf("\n element not  found please try again");
    }
    else
    {
        printf("\n element %d found at %d position ",el,m+1);
    }    
    return 0;
}
int Lsearch( int A[], int n,int el)
{
    for(int i=0;i<n;i++)
    {
        if(A[i]==el)
        {
            return i;
        }
        
    }
    return -1;

}