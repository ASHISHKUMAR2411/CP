#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
// int f(int x,int *py,int **ppz)
// {
//      int z,y;
//     **ppz+=1;
//     z=**ppz;
//     *py+=2;
//     y=*py;
//     x+=3;
//     return x+y+z;
// }
int main()
{
    char a[10]="asdfghgwe";
    char *p=a;
    fun(&a[5]);
    // c=4;
    // b=&c;
    // a=&b;
    
    // while(i>0)
    // {
    //     x=fun(i);
    //     i--;
    // }    
    

}
void fun( char b[])
{
    puts(b);
}