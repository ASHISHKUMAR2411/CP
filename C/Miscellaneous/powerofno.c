#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>


int main()
{
    int m,w,n,sum=1;
    double p;
    float fm;
     char ch[10];
    printf("\n enter the number in integer on which you want apply to the power \t");
    gets(ch);
    n=atoi(ch);
    //p=atof(&ch[0]);
    //fm=strtof(ch);
    printf("\n now enter the power you want on the number \t");
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        sum*=n;
        //p*=p;
        //fm*=fm;
    }
    w=pow(atoi(ch),m);
    printf("\n the number is %d \n\t\t %d",w+1,sum);
   // printf("\n\t%1.6f",(float)atof(ch));
    //printf("\n\t%1.6f",(float)atoi(ch));
    return 0;

}