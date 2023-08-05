#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define pi 3.14
#define max 180
int main()
{
    int angle=0;
    float x,y;
    printf(" \t  Angle  \t Cos(Angle) \n\n");
    while (angle<=180)
    {
        /* code */
        x=(pi)*(float)angle/(max);
        y=cos(x);
        printf("%15d %13.4f \n ",angle,y);
        angle+=10;
    }
    return 0;
}