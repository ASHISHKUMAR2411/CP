#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char ch1,ch2,ch3,ch4,ch5,ch6;
    printf("\ndo you know more about me  \n enter Y or y for yes\t");
    scanf("%c",&ch1);
    switch(ch1)
    {
        case 'Y': 
                  printf("\n my name is Ashish Kumar");
                 break;
        case 'y':
                 printf("\n my name is Ashish Kumar");
                 break;
        default: printf("\n Appreciate for your time");
                exit(0);
                break;                 
    }
    printf("\n do you know more about me  \n enter Y or y for yes \t");
    scanf("%c",&ch2);
    scanf("%c",&ch2);
    switch(ch2)
    {
        case 'Y': 
                  printf("\n I am from renukoot");
                 break;
        case 'y':
                 printf("\n I am from renukoot");
                 break;
        default: printf("\n Appreciate for your time");
                exit(0);
                break;                 
    }
    printf("\ndo you know more about me  \n enter Y or y for yes\t");
    scanf("%c",&ch3);
    scanf("%c",&ch3);
    switch(ch3)
    {
        case 'Y': 
                  printf("\n I am currently studing in Indian Institute Of Information Technology ,Kota ,but studing in Jaipur in MNIT");
                 break;
        case 'y':
                 printf("\n I am currently studing in Indian Institute Of Information Technology,Kota but studing in Jaipur MNIT");
                 break;
        default: printf("\n Appreciate for your time");
                exit(0);
                break;                 
    }
     printf("\ndo you know more about me  \n enter Y or y for yes\t");
    scanf("%c",&ch4);
    scanf("%c",&ch4);
    switch(ch4)
    {
        case 'Y': 
                  printf("\n My JEE CRL rank was 39043 and MY Category was 9999\n I have Qualified JEE Advance with CRL 20142 rank and Category rank was 4545 ");
                 break;
        case 'y':
                 printf("\nMy JEE CRL rank was 39043 and MY Category was 9999\n I have Qualified JEE Advance with CRL 20142 rank and Category rank was 4545");
                 break;
        default: printf("\n Appreciate for your time");
                exit(0);
                break;                 
    }
    printf("\ndo you know more about me  \n enter Y or y for yes\t");
    scanf("%c",&ch5);
    scanf("%c",&ch5);
    switch(ch5)
    {
        case 'Y': 
                  printf("\n My Mother's name is CHINTU DEVI and she is a Housewife \n and My father's Name is Dhaneshwar Prasad and he works at HINDALCO INDUSTRIES LIMITED , RENUKOOT  ");
                 break;
        case 'y':
                 printf("\nMy Mother's name is CHINTU DEVI and she is a Housewife \n and My father's Name is Dhaneshwar Prasad and he works at HINDALCO INDUSTRIES LIMITED , RENUKOOT ");
                 break;
        default: printf("\n Appreciate for your time");
                exit(0);
                break;                 
    }
    printf("\ndo you know more about me  \n enter Y or y for yes\t");
    scanf("%c",&ch6);
    scanf("%c",&ch6);
    switch(ch6)
    {
        case 'Y': 
                  printf("\n MY family also includes 3 siblings\neldest one is married \none is doing job in IT sector \nand younger one is preparing for government job  ");
                 break;
        case 'y':
                 printf("\n MY family also includes 3 siblings\neldest one is married \none is doing job in IT sector \nand younger one is preparing for government job  ");
                 break;
        default: printf("\n Appreciate for your time\nthank you for your time ");
                break;

    }
    return 0;
}