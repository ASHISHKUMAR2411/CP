#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[50],n,i,temp=0;
    char ch;
    scanf("%d",&n);
    for( i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        // printf("\n would you like to enter the next element enter Y/y for yes : ");
        // scanf("%c",&ch);
        // scanf("%c",&ch);
        // if(ch!='y'||ch!='Y')
        // {
        //     break;
        // }
    }
    // while(i<n)
    // {
    //      a[i]=-1;
    // }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(a[j]==i)
            {
                temp=a[j];
                a[j]=a[i];
                a[i]=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]!=i)
        {
            a[i]=-1;
        }
    }
    printf("\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}