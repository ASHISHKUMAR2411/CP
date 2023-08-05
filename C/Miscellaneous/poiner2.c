#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
struct Ash
{
    char name[27];
    char Id[15];
    int  rollno;
} stu[5], *ptr;
int main()
{
    // structure and pointer
    char ch[1];
    for (ptr = stu; ptr < stu + 5; ptr++)
    {
       printf("\n name : ");
       gets(ch);
       gets(ptr->name);
       printf("\n ID : ");
       gets(ptr->Id);
       printf("\n Roll No : ");
       scanf("%d",&ptr->rollno);
    }
    ptr = stu;
    printf("\n %d", ptr->rollno);
    printf("\n%s", ptr->name);
    printf("\n%s", ptr->Id);
    ptr++;
    printf("\n %d", ptr->rollno);
    printf("\n %s", (*ptr).name);
    printf("\n %s", (*ptr).Id);
    for (ptr = stu; ptr < stu + 5; ptr++)
    {
        printf("\n Roll no : %d  Name : %s  ID : %s ", ptr->rollno, (*ptr).name ,ptr->Id);
    }
    return 0;
}
    
