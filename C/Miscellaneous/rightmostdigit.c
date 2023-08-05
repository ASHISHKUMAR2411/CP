#include<stdio.h>
#include<stdlib.h>
int main()
{
    int m;
    float n; 
    printf("\nenter the float value whose right most digit you want to find before decimal \t");
    scanf("%f",&n);
    m=(int)n;
    m=m%10;
    printf("\n the right most digit is %d \t",m);
    return 0;

}