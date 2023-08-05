#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int response( void);
int print(void);
void askuser(void);
float input(void);
float add(float a, float b);
float sub(float a, float b );
float mul(float a,float b);
float divi(float a, float b);
float modu(float a , float b);
void last(void); 
int main()
{
    // calculator;
    if(response())
    {
        if(print())
        {
            askuser();
            printf("\n do you want to find remainder of two number");
            if(print())
            {
                float a,b,c;
                a=input();
                b=input();
                c=modu(a,b);
                printf("\n the modulus  value is %f",c);
            }
            else
            {
                last();
            }

        }
        else 
        {
            last();
        }
    }
    else
    {
        last();
    }
    return 0;

}
int response( void)
{
    char ch;
    printf("\n enter Y/y for peforming calculator \t : ");
    scanf("%c",&ch);
    if(ch=='Y'|| ch=='y')
    return 1;
    else
    return 0;
}
int print(void)
{
    char ch;
   printf("\n Do you want to enter the values press Y/y  to perform arthimatic operation \t : ");
   scanf("%c",&ch);
   if(ch=='Y'|| ch=='y')
    return 1;
    else
    return 0; 

}
void askuser(void)
{
    char ch;
    float a,b,c;
    printf("\n first tell us which activity you want to perform \t");
    printf("\n press A or a for addition \n press S or s for substraction \n press M or m for multiplication \n press D or d for division ");
    scanf("%c",&ch);
    switch (ch)
    {
        case 'a':
        case 'A' : printf("\n okay we will perform the addition ");
                   a=input();
                   b=input();
                   c=add(a,b);
                   printf("the sum is %f ",c);
                   break;
        case 's':
        case 'S':
                   printf("\n okay we will perform the subtraction ");
                   a=input();
                   b=input();
                   c=sub(a,b);
                   printf("the subtrachend  is %f ",c);
                   break;
        case 'm':
        case 'M':           

                   printf("\n okay we will perform the multiplication ");
                   a=input();
                   b=input();
                   c=mul(a,b);
                   printf("the product is %f ",c);
                   break;
        case 'd':
        case 'D':

                   printf("\n okay we will perform the division is ");
                   a=input();
                   b=input();
                   c=divi(a,b);
                   printf("the divsion is %f ",c);
                   break;
        default : printf("\n wrong choice please try again \n");
                  last();           

    }
}
float input(void)
{
    float f;
    printf("\n enter the number you want to operate \t: ");
    scanf("%f",&f);
    return (f);

}
float add(float a, float b)
{
    float f;
    f=a+b;
    return (f);
}
float sub(float a, float b)
{
    float f;
    f=a-b;
    return (f);
}
float mul(float a,float b)
{
    float f;
    f=a*b;
    return (f);
}
float divi(float a, float b)
{
   
   float f;
    f=a/b;
    return (f);
}
float modu(float a , float b)
{
   float f;
    f=(float)((int)a%(int)b);
    return (f);

}
void last(void)
{
    printf("\n thank you for your time");
}
