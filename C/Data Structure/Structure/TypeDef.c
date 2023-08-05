#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct 
{
    char name[50];
    char fname[50];
    int salary;
}Ashish;
int main()
{
    Ashish stu[3];
    char ch[10];
    for(int i=0;i<3;i++)
    { 
        gets(ch);
        printf("\n enter the name ");
        gets(stu[i].name);
        printf("\n enter the father name of the student ");
        gets(stu[i].fname);
        printf("\n enter the salary ");
        scanf("\n%d",&stu[i].salary);
    }
    printf("\n now show the deatil \n");
    for(int i=0;i<3;i++)
    {
        printf("\n  the name :");
        puts(stu[i].name);
        printf("\n  the father name of the student :");
        puts(stu[i].fname);
        printf("\n  the salary : %d",stu[i].salary);
        
    }
    return 0;
}
