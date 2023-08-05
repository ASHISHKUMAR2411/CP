#include<stdio.h>
#include<string.h>
void Lisearch( int A[][15], int m ,int n,int el);
int main()
{
    // search using linear  search in 2D array
    int A[20][15],n,el,m,p;
    printf("\n enter the number of row you want to enter in the matrix : \t");
    scanf("%d",&m);
    printf("\n enter the number of column you want to enter in the matrix : \t");
    scanf("%d",&n);
    printf("\n enter the elements of the array \n");
    for(int i=0;i<m;i++)
    {
        printf("\n enter the %d row elements  ",i+1);
        for(int j=0;j<n;j++)
        {
          printf("\nenter the %d column  elements of %d row: \t ",j+1,i+1);
          scanf("%d",&A[i][j]);
        }
    }    
    printf("\n enter the element to seach \t ");
    scanf("%d",&el);
    Lisearch(A,m,n,el);
    
    // if(m==-1)
    // {
    //     printf("\n element not  found please try again");
    // }
    // else
    // {
    //     printf("\n element %d found at %d position ",el,m+1);
    // }    
    // return 0;
}
void Lisearch( int A[][15], int m,int n,int el)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        if(A[i][j]==el)
        { 
            printf("element found at %d row and %d column",i+1,j+1);
            
        }
        
    }
   
        printf("\n element not found plz try again");

    

}