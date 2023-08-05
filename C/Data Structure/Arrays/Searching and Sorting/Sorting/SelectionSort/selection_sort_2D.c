#include<stdio.h>
#include<stdlib.h>
void selection_sort(int **A,int m,int n);
int main()
{
    int m,n,**A;
    printf("\n enter the number of rows : ");
    scanf("%d",&m);
    printf("\n enter the number of column : ");
    scanf("%d",&n);
    A=(int **)malloc(m*n*sizeof(int));
    for(int i=0;i<m;i++)
    {
        printf("\n%d row",i+1);
        for(int j=0;j<n;j++)
        {
            printf("\n%d column :",j+1);
            scanf("%d",&A[i][j]);
        }
    }
    selection_sort(A,m,n);
    for(int i=0;i<m;i++)
    {
        printf("\n");
        for(int j=0;j<n;j++)
        {
            printf("%d ",A[i][j]);
        }
    }
    return 0;
}
void selection_sort(int **A,int m,int n)
{
    int i,j,k,l,pos1,pos2,min,temp;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            pos1=i;
            pos2=j;
            min=A[i][j];
            for(k=i;k<m;k++)
            {
                if(k==i)
                {
                    for(l=j;l<n;l++)
                    {
                        if(A[k][l]<min)
                        {
                            pos1=k;
                            pos2=l;
                            min=A[k][l];
                        }
                    }
                }
                else
                {
                    for(l=0;l<n;l++)
                    {
                        if(A[k][l]<min)
                        {
                            pos1=k;
                            pos2=l;
                            min=A[k][l];
                        }
                    }
                }
            }
            temp=A[i][j];
            A[i][j]=A[pos1][pos2];
            A[pos1][pos2]=temp;
        }
    }
}