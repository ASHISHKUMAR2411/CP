// using recursion we are finding recrusion 
#include<stdio.h>
int fact(int i);
int main()
{
    int n,fa;
    scanf("%d",&n);
    if(n==0)
    {
        fa=1;
    }
    else
    {
        fa=fact(n);
    }
    printf("%d",fa);
    return 0;
}
int fact(int i)
{
    if(i==1)
    {
        return(i);
    }
    else
    {
        return (i*fact(i-1));
    }
}
