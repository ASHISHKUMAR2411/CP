// structure and function
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Scholarship
{
    char Name[50];
    int Family_income;
    char Email_id[100];
    char Collegename[200];
    char College_tier;
} student;
void give(struct Scholarship A);
int main()
{

    char ch[5];

    printf("\n enter the name of the students: \t  ");
    gets(student.Name);
    printf("\n enter the family income of the student family: \t ");
    scanf("%d", &student.Family_income);
    printf("\n enter the email id of the student:\t ");
    gets(ch);
    gets(student.Email_id);
    printf("\n enter the college name of the student : \t ");
    gets(student.Collegename);
    printf("\n enter the college tier as either A,B or C : ");
    scanf("%c", student.College_tier);

    give(student);
    return 0;
}
void give(struct Scholarship A)
{

    
        if(A.Family_income<600000)
        {
            if(A.College_tier == 'A' || A.College_tier == 'a')
            {
                printf("\n congratulation %s  you are selected for the scholarship", A.Name);
                printf("\n your amount will be transfered to your account ");
            }
            else
            {
                printf("\n Sorry to say but you are not selected as We have recieved many profile and it was a very tough for us also ");
                printf("\n Mr/Ms %s this does not mean we don't understand your condition but we have to do this ", A.Name);
            }
        }
        else
        {
            printf("\n Mr/Ms %s profile does not match with our criteria ", A.Name);
        }
    
}