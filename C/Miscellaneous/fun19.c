#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
float f(float f1);
int main()
{
    // to print the f(x)=x-x^3/3!+x^5/5! ......
    float x,z;
    printf("\n enter the number the x \t");
    scanf("%f",&x);
    z=f(x);
    printf("\n %f ",z);
    return 0;
 
} 
float f(float f1)
{
    static int flag=1,sign=1,fact=1,i=1,z;
    static float sum=0.0;
    z*=fact;
    if(i%2!=0)
    {
        
        sum = sum + (sign * pow(f1,i)/z);
        sign*=-1;
                 
    }
    i++;
    fact++;
    printf("\n%f",sum);
    f(f1);
    
    return (sum);
    

}


