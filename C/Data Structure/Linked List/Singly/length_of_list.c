
#include<stdio.h>
#include<stdlib.h>
struct ll
{
    int data;
    struct ll *next;
};
struct ll *create()
{
    int data;
    struct ll *temp=(struct ll *)malloc(sizeof(struct ll));
    printf("\n enter the data ");
    scanf("%d",&data);
    temp->data=data;
    temp->next=NULL;
    return temp;
}
void insert(struct ll *ptr)
{
    struct ll *pre;
    while(ptr!=NULL)
    {
        pre=ptr;
        ptr=ptr->next;
    }
    int data;
    struct ll *temp=(struct ll *)malloc(sizeof(struct ll));
    printf("\n enter the data : ");
    scanf("%d",&data);
    temp->data=data;
    temp->next=NULL;
    pre->next=temp;
}
void deletion(struct ll *ptr)
{
    int pos,count=0;
    struct ll *pre;
    printf("enter the position to delete : ");
    scanf("%d",&pos);
    while(ptr!=NULL && count<pos)
    {
        pre=ptr;
        count++;
        ptr=ptr->next;
    }
    pre->next=ptr->next;
}
void length(struct ll *ptr)
{
    int count=0;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->next;
    }
    printf("\n%d",count);
}
void print(struct ll *ptr)
{
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
int main()
{
    struct ll *head,*ptr;
    head=create();
    int choice;
    char ch;
    do
    {
        printf("\n1.Insert");
        printf("\n2.delete");
        printf("\n3.length");
        printf("\n4.print");
        printf("\n5.exit");
        printf("\n");
        label:
        printf("\n enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            insert(head);
            break;
            case 2:
            deletion(head);
            break;
            case 3:
            length(head);
            break;
            case 4:
            print(head);
            break;
            case 5:
            exit(0);
            break;
            default : 
            printf("\n you have entered the wrong choice  ");
            goto label;
        }
        printf("\n enter y/Y for more operation : ");
        scanf("%c",&ch);
        scanf("%c",&ch);
    } while (ch=='y'||ch=='Y');
    

}