#include<stdio.h>
#include<stdlib.h>
int main()
{
    int r,c,count=0,len=0;
     scanf("%d",&r);
     scanf("%d",&c);
     int *ptr,**arr;
     len=r*sizeof(int *)+r*c*sizeof(int);
     arr=(int **)malloc(len);
     ptr=(int *)(arr+r);
     for(int i=0;i<r;i++)
     {
         arr[i]=(ptr + c*i);
     }
     for(int i=0;i<r;i++)
     {
         for(int j=0;j<c;j++)
         {
             arr[i][j]=count++;
         }
     }
     for(int i=0;i<r;i++)
     {
         for(int j=0;j<c;j++)
         {
             printf("%3d ",arr[i][j]);
         }
         printf("\n");
     }
}