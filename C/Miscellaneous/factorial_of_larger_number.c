// algorithm
// for each number we are first amking a array of large size 
// then we are intiliasing the size as 1 and its first element of array as 1
// then we are for x=2 to n where n is the number whose factorial we are finding
// size is reset by multiplyong with x and saving the next number to x[1]and carry as x[0]
// here we are multiply the x with whole array at each time and shifty its value one step left
// and doing the same for next n times anf output the array
#include<stdio.h>
#include<stdlib.h>
#define max 200 
void fact(int n);
int multi(int x,int size,int a[]);
int main()
{
    int n;
    scanf("%d",&n);
    fact(n);
    return 0;
}
void fact(int n)
{
    int res[max];
    res[0]=1;
    int size=1;
    for(int x=2;x<n;x++)
    {
        size=multi(x,size,res);
    }
    for(int i=size-1;i>=0;i--)
    {
        printf("%d",res[i]);
    }
}
int multi(int x,int size,int a[max])
{
    int carry=0;
    for(int i=0;i<size;i++)
    {
        int product=a[i]*x+carry;
        a[i]=product%10;
        carry=product/10;
    }
    while(carry)
    {
        a[size]=carry%10;
        carry=carry/10;
        size++;
    }
    return size;
}