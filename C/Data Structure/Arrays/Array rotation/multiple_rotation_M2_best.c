#include<stdio.h>
#include<stdlib.h>
void copy(int *p,int n,int *temp);
void rotate(int *p,int n,int k,int *temp);
int main()
{
    int n,a[20],temp[40],d,m;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    copy(a,n,temp);
    printf("\nenter the number of times you want to rotate : ");
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        printf("\n enter the number od roattion:  ");
        scanf("%d",&d);
        rotate(a,n,d,temp);
    }

}
void copy(int *p,int n,int *temp)
{
    for(int i=0;i<n;i++)
    {
        temp[i]=p[i];
        temp[i+n]=p[i];
    }
}
void rotate(int *p,int n,int k,int *temp)
{
    int start=k%n;
    for(int i=start;i<start+n;i++)
    {
        printf("%d ",temp[i]);
    }
}