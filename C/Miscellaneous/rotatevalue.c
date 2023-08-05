#include<stdio.h>
#include<stdlib.h>
int main()
{

    int m,x,y,z;
    printf("\n enter the value of x ,y , z , by giiving spaces between them \t");
    scanf("%d %d %d",&x,&y,&z);
    m=x;
    x=y;
    y=z;
    z=m;
    printf("the new value of \nx=%d\ny=%d\nz=%d",x,y,z);
    return 0;
}
