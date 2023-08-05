#include<stdio.h>
void sort(int A[],int n);
void read( int A[],int n);
void merge(int A[],int m,int B[],int n);
void print(int C[], int m);
int main()
{
    // sorting and merging in ascending order
    int A[30],B[30],m,n;
    printf("\nenter the number of elemnts in  array 1 ");
    scanf("%d",&m);
    printf("\nenter the number of elemnts in  array 2 ");
    scanf("%d",&n);
    read(A,m);
    read(B,n);
    sort(A,m);
    sort(B,n);
    merge(A,m,B,n);
    return 0;
}
void sort(int A[],int n)
{
    int temp=0;
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<n-1;j++)
       {
           if(A[j]>A[j+1])
           {
               temp=A[j];
               A[j]=A[j+1];
               A[j+1]=temp;
           }
       }
   }
}
void  read( int A[],int n )
{
    for(int i=0;i<n;i++)
    {
        printf("\n enter the element of the array %d \t  ",i+1);
        scanf("%d",&A[i]); 
    }
}
void merge(int A[],int m,int B[],int n)
{
    int i=0,j=0,k=0,C[100],l;
    while(i<m&&j<n)
    {
        if(A[i]<B[j])
        {
            C[k++]=A[i++];
        }
        else
        {
            C[k++]=B[j++];
        }

    }
    while(i<m)
    {
        C[k++]=A[i++];
    }
    while(j<n)
    {
        C[k++]=B[j++];
    }
    l=k;
    print(C,l);
}
void print(int C[], int m)
{
    printf("\n");
    for(int i=0;i<m;i++)
    {
        printf("%d ",C[i]);
    }
}