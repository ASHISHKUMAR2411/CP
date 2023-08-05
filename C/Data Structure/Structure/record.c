#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct student_record
{
    char name[50];
    char dob[15];
    int totalmarks;
} student[10];
int main()
{
    // printing data of 10 student using structure
    int i, j;
    char ch[10];
    struct student_record temp = {"\0", "\0", 0};
    for (i = 0; i < 10; i++)
    {
        printf("\n enter the name of the %d student : \t", i + 1);
        gets(ch);
        gets(student[i].name);
        printf("\n enter the date of birth of the %d student :\t ", i + 1);
        
        gets(student[i].dob);
        printf("\n enter the totalmarks of the %d student : \t ", i + 1);
        scanf("%d", &student[i].totalmarks);
    }
    for (j = 0; j < 10; j++)
    {
        for (int k = 0; k < 9; k++)
        {
            if (student[k].totalmarks < student[k + 1].totalmarks)
            {
                temp = student[k];
                student[k] = student[k + 1];
                student[k + 1] = temp;
            }
        }
    }
    printf("\n now printing the student record rankwise ");
    for(i=0;i<10;i++)
    {
        printf("\n the name of %d student in the class is : %s ",i+1,student[i].name);
        printf("\n dob is : %s",student[i].dob);
        printf("\n totalmarks is : %d",student[i].totalmarks);
    }
    return 0;
}
