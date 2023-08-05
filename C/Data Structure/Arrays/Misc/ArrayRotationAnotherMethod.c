// this method is called block swap method
// in this method we can try to do is that first we seperate the array in two array i.e A[0,d-1] and B[d,n-1] here A is the block which we have to swap at the end and B is the bloock to come forward 
// what we do here is 
// 1. we have to do the following step untill Size of A is equal to size of B 
//   a. if A is shorter , divide the B into two small array as BL as Bleft and BR as Bright 
//      such that the size of BR is same as A so that we can swap A with BR as our motive is
//      is to bring block A into end , after doing that we get ABLBR to BRBLA , now we have 
//      A at its final place we have to recur the BR and BL. we can do one thing more is we 
//      can copy the whole string B from the starting of the BRBLA. we will get the same 
//      thing  .
//   b. if A is longer , divide the A into two small array as AL as Aleft and AR as Aright 
//      such that the size of B is same as AL so that we can swap AL with B as our motive is
//      is to bring block B into front first  , after doing that we get ALARB to BARAL,we 
//      have B at its final place we have to recur the AL and AR. we can do one thing more 
//      is we can copy the whole string A from the ending B in the BARAL. we will get the    
//      same thing  .
// 2. finally A and B are of the same size now block swap them 
// time complexity is O(n).

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void rotate(int *a,int n,int d);
void swap(int *a,int fi,int si, int d);
int main()
{
    int n,d,a[20];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\n enter the rotation");
    scanf("%d",&d);
    rotate(a,n,d);
    
    for(int i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
    return 0;
}
void rotate(int *a,int n,int d)
{
    if(d==0||d==n)
    return ;
    if(n-d==d)//i.e when the roatation is for half of the array(A and B are of equal size)
    {
        swap(a,0,n-d,d);
        return;
    }
    if(d<n-d)//A is shorter
    {
       swap(a,0,n-d,d);
       rotate(a,d,n-d);
    }
    else // B is shorter
    {
        swap(a,0,d,n-d);
        rotate(a+n-d, 2*d -n , d);`
    }
}
void swap(int *a,int fi,int si, int d)
{
    int i,tenp;
    for(i=0;i<d;i++)
    {
        tenp=a[fi+i];
        a[fi+i]=a[si+i];
        a[si+i]=tenp;
    }
}