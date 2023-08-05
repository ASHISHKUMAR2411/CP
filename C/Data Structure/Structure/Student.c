#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
struct STUDENT
{
    int Rollno;
    char name[50];
    char studentid[50];
    char mailid[100];
    char instituteid[100];
    char address[100];
    float fees;
    char booksname[50];
    char collegename[200];
    char collegeaddress[200];
} stu[2];

int main()
{
    // using structure
    char ch[10] ;
    struct STUDENT stu3={1008,"Ashish Kumar","2020kucp1008","ashishkumar24112001@gmail.com","2020kucp1008@iiitkota.ac.in","N-2796 Hindalco colony Renukoot 231217",126925.00,"Balaguruswamy","Indian Institute Of Information Technology Kota","MNIT campus ,JLN Marg, Jaipur "};
    printf("\n now enter the details asked for the form ");
    gets(ch);
    for(int i=0;i<2;i++)
    {
        printf("\n enter the student roll no : \t");
        scanf("%d",&stu[i].Rollno);
        printf("\n enter the student name : \t");
        gets(ch);
        gets(stu[i].name);
        printf("\n enter the student  ID given by College: \t ");
        gets(stu[i].studentid);
        printf("\n enter the student personal email : \t ");
        gets(stu[i].mailid);
        printf("\n enter the student email ID giievn by college : \t ");
        gets(stu[i].instituteid);
        printf("\n enter the student  address : \t ");
        gets(stu[i].address);
        printf("\n enter the  fees submit by student   : \t ");
        scanf("%f",&stu[i].fees);
        printf("\n enter the book name given to  student  : \t ");
        gets(ch);
        gets(stu[i].booksname);
        printf("\n enter the college name of student  : \t ");
        gets(stu[i].collegename);
        printf("\n enter the college address   : \t ");
        gets(stu[i].collegeaddress);

    }
    printf("\n now showing what the value entered by student \n ");
    for(int i=0;i<2;i++)
    {
        printf("\nthe student roll no :%d \t",&stu[i].Rollno);
        printf("\n the student name : \t");
        puts(stu[i].name);
        printf("\n the student  ID given by College: \t ");
        puts(stu[i].studentid);
        printf("\n the student personal email : \t ");
        puts(stu[i].mailid);
        printf("\n the student email ID giievn by college : \t ");
        puts(stu[i].instituteid);
        printf("\n the student  address : \t ");
        puts(stu[i].address);
        printf("\n the  fees submit by student   : \t %f",stu[i].fees);
        printf("\n the book name given to  student  : \t ");
        puts(stu[i].booksname);
        printf("\n the college name of student  : \t ");
        puts(stu[i].collegename);
        printf("\n the college address   : \t ");
        puts(stu[i].collegeaddress);

    }
    printf("\nthe student roll no :%d \t ",&stu3.Rollno);
    printf("\n the student name : \t");
    puts(stu3.name);
    printf("\n the student  ID given by College: \t ");
    puts(stu3.studentid);
    printf("\n the student personal email : \t ");
    puts(stu3.mailid);
    printf("\n the student email ID giievn by college : \t ");
    puts(stu3.instituteid);
    printf("\n the student  address : \t ");
    puts(stu3.address);
    printf("\n the  fees submit by student   : \t %f",stu3.fees);
    printf("\n the book name given to  student  : \t ");
    puts(stu3.booksname);
    printf("\n the college name of student  : \t ");
    puts(stu3.collegename);
    printf("\n the college address   : \t ");
    puts(stu3.collegeaddress);
    stu3=stu[1];
    printf("\nthe student roll no : %d \t ",&stu3.Rollno);
    printf("\n the student name : \t");
    puts(stu3.name);
    printf("\n the student  ID given by College: \t ");
    puts(stu3.studentid);
    printf("\n the student personal email : \t ");
    puts(stu3.mailid);
    printf("\n the student email ID giievn by college : \t ");
    puts(stu3.instituteid);
    printf("\n the student  address : \t ");
    puts(stu3.address);
    printf("\n the  fees submit by student   : \t %f",stu3.fees);
    printf("\n the book name given to  student  : \t ");
    puts(stu3.booksname);
    printf("\n the college name of student  : \t ");
    puts(stu3.collegename);
    printf("\n the college address   : \t ");
    puts(stu3.collegeaddress);
    return 0;
}