#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// NOTE : here we can't make upto many students in the list so we are just taking lesser inputs for the same ;
struct Student
{
    char iD[15];
    int rollNo;
    char batch;
    int size;
    char name[0];
};
struct Student *createStudent(struct Student *stu)
{
    int rN;
    char id[15],bat,stuName[40],ch;
    while((getchar())!='\n');
    printf("\nEnter your Name : ");
    gets(stuName);
    printf("\nEnter The ID : ");
    gets(id);
    printf("\nEnter your rollNo : ");
    scanf("%d",&rN);
    while((getchar())!='\n');
    printf("\nEnter your BATCH : ");
    scanf("%c",&bat);
    stu = (struct Student *)malloc(sizeof(stu)+sizeof(char)*strlen(stuName));
    if(stu==NULL)
    {
        printf("\n no memory allocation ");
        return stu;
    }
    stu->batch = bat;
    strcpy(stu->iD, id);
    strcpy(stu->name,stuName);
    stu->rollNo = rN;
    stu->size = (sizeof(stu)+ sizeof(char)*strlen(stu->name));
    return stu;
}

void printStudent(struct Student *stu)
{
    printf("Stud_Name : %s\n"
           "Student_id : %s\n"
           "Student_RollNo : %d\n"
           "Student_BATCH : %d\n"
           "Name_Length: %d\n"
           "Allocated_Struct_size: %d\n\n",
           stu->name,stu->iD, stu->rollNo,stu->batch, strlen(stu->name),stu->size);

    //Value of Allocated_Struct_size here is in bytes.
}

int main()
{
    int size;
    printf("\nEnter The size of List Of the Student\n You want : ");
    scanf("%d",&size);
    struct Student **student = (struct Student **)malloc(size*sizeof(struct Student *));
    if(student == NULL)
    {
        printf("\n no memeory for parent ");
        exit(0);
    }
    int i;
    for( i =0; i<size-3;i++)
    {
        if(student[i]==NULL)
        {
            printf("\n no memeory for element ");
            break;
        }
        student[i] = createStudent(student[i]);
    }
    printf("\n You Have The Following List OF Student : \n");
    for(int j =0 ;j< i ; j++)
    {
        printStudent(student[j]);
    }
    for(int j =0 ;j< i;j++)
    {
        free(student[j]);
    }
    free(student);
}