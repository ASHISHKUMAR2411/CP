// passing the structure pointer as function
#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
struct POINTER
{
    int a ;
    float f;
    char c;
    char ch[20];
}s[5],*p,(*ptr)[10];
void Print(struct POINTER *P);
void Read(struct POINTER *P);
int main()
{
    // int n;
    // char ch1[1],ch2[1],ch3[1];
    // p=s;
    // printf("\n ener the numbrer of student report you want to see : ");
    // scanf("%d",&n);
    printf("\n now give the inputs to store data of the student : ");
    // for(int i=0;i<5;i++)
    // {
    //     printf("\n enter the name : ");
    //     gets(ch2);
    //     gets(p->ch);
    //     printf("\n enter the mark1 : ");
    //     scanf("%d",&p->a);
    //     printf("\n enter the grade : ");
    //     gets(ch3);
    //     scanf("%c",&p->c);
    //     printf("\n enter the total marks : ");
    //     gets(ch1);
    //     scanf("%f",&p->f);
    //     p++;
    // }
    Read(s);
    Print(s);
    return 0;
}
void Read(struct POINTER *P)
{
    char ch1[1],ch2[1],ch3[1];
    for(int i=0;i<5;i++)
    {
        printf("\n enter the name : ");
         gets(ch2);
        gets(P->ch);
        printf("\n enter the mark1 : ");
       
        
        scanf("%d",&P->a);
        printf("\n enter the grade : ");
        gets(ch3);
        scanf("%c",&P->c);
        printf("\n enter the total marks : ");
        gets(ch1);
        scanf("%f",&P->f);
        P++;
    }

}
void Print(struct POINTER *P)
{
    for(int i=0;i<5;i++)
    {
       printf("\n Name : %s",P->ch);
       printf("\n MARKS :%d ",P->a);
       printf("\n Grade :%c",P->c);
       printf("\n Total :%f ",P->f);
       P++;
    }

}