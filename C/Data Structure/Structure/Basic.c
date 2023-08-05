#include<stdio.h>
#include<stdlib.h>
struct mark
{
    int mark1;
    int mark2;
    int mark3;
} stu[3];

int main()
{
    int total[3]={0,0,0},subject[3]={0,0,0};
    for(int i=0;i<3;i++)
    {
        printf("\n enter the student marks in 1st subject \t ");
        scanf("%d",&stu[i].mark1);
        printf("\n enter the student marks in 2nd subject \t ");
        scanf("%d",&stu[i].mark2);
        printf("\n enter the student marks in 3rd subject \t ");
        scanf("%d",&stu[i].mark3);
    }
    printf("\n now showing the result of the exam ");
    for(int i=0;i<3;i++)
    {
        printf("\n enter the student marks in 1st subject \t : %d",stu[i].mark1);
        printf("\n enter the student marks in 2nd subject \t %d",stu[i].mark2);
        printf("\n enter the student marks in 3rd subject \t %d",stu[i].mark3);
    }
    
    
        for(int j=0;j<3;j++)
        {
            subject[0]+=stu[j].mark1;
            subject[1]+=stu[j].mark2;
            subject[2]+=stu[j].mark3;
        }
        for(int j=0;j<3;j++)
        {
            total[j]=stu[j].mark1+stu[j].mark2+stu[j].mark3;
        }
        for(int i=0;i<3;i++)
        {
            printf("\n subject %d  %d \t total %d student %d",i+1,subject[i],i+1,total[i]);
        }
        return 0;
    

}