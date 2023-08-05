#include<stdio.h>
#include<stdlib.h>
struct dll
{
    int data ;
    struct dll *next;
    struct dll *prev;
};
struct dll *create()
{
    int data;
    struct dll *temp=(struct dll *)malloc(sizeof(struct dll));
    printf("\n enter the data ");
    scanf("%d",&data);
    temp->data=data;
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
}
void insert(struct dll *ptr)
{
    struct dll *pre;
    while(ptr!=NULL)
    {
        pre=ptr;
        ptr=ptr->next;
    }
    int data;
    struct dll *temp=(struct dll *)malloc(sizeof(struct dll));
    printf("\n enter the data : ");
    scanf("%d",&data);
    temp->data=data;
    temp->next=NULL;
    temp->prev=NULL;
    pre->next=temp;
}
void deletion(struct dll *ptr)
{
    int pos,count=0;
    struct dll *pre;
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
int length(struct dll *ptr)
{
    int count=0;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->next;
    }
    // printf("\n%d",count);
    return count;
}
void print(struct dll *ptr)
{
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
void middle(struct dll *ptr)
{
    struct dll *pre,*post;
    pre=ptr;
    post=ptr;
    // int count=0,len=length(ptr);
    while(post->next!=NULL && post!=NULL)
    {
        pre=pre->next;
        post=(post->next)->next;
    }
    printf("\n%d",pre->data);
}
void count(struct dll *ptr)
{
    int temp,count=0;
    printf("\n enter the integer to count ");
    scanf("%d",&temp);
    while(ptr!=NULL)
    {
        if(ptr->data==temp)
        {
            count++;
        }
        ptr=ptr->next;
    }
    printf("\n the count is : %d",count);
}
void make_random_list(struct dll *ptr)
{
    int data;
    struct dll *pre=ptr,*ctr=NULL;
    while(pre!=NULL)
    {
        up:
        printf("\n you have these option with which you can connect : ");
        print(ptr);
        printf("\nenter the data with which yo want to connect with %d :",pre->data);
        scanf("%d",&data);
        ctr=ptr;
        while(ctr!=NULL)
        {
           if(ctr->data==data)
           {
               break;
           }
           ctr=ctr->next;
        }
        if(ctr==NULL)
        {
           printf("\n enter the data again ");
           goto up;
        }
        pre->prev=ctr;
        pre=pre->next;
    }
    print_back(ptr);
}
void copy_node(struct dll *ptr,int data)
{
    struct dll *pre=ptr,*ctr=ptr;
    while(ctr!=NULL)
    {
        pre=ctr;
        ctr=ctr->next;
    }
    struct dll *temp=(struct dll *)malloc(sizeof(struct dll));
    temp->data=data;
    temp->next=NULL;
    temp->prev=NULL;
    pre->next=temp;
}
void print_back(struct dll *ptr)
{
    struct dll *pre=ptr;
    while(pre!=NULL)
    {
        printf("%d ",(pre->prev)->data);
        pre=pre->next;
    }
    return;
}
void clone_list(struct dll *ptr)
{
    struct dll *pre=ptr,*cre=NULL,*ctr=NULL,*curr=NULL;
    ctr=(struct dll *)malloc(sizeof(struct dll));
    ctr->data=pre->data;
    ctr->next=NULL;
    ctr->prev=NULL;
    cre=ctr;
    pre=pre->next;
    while(pre!=NULL)
    {
        copy_node(ctr,pre->data);
        pre=pre->next;
    }
    cre=ctr;
    pre=ptr;
    while(pre!=NULL && cre!=NULL)
    {
        curr=ctr;
        while(curr!=NULL)
        {
            if(curr->data==(pre->prev)->data)
            {
                break;
            }
            curr=curr->next;
        }
        cre->prev=curr;
        pre=pre->next;
        cre=cre->next;
    }
    print_back(ctr);
    printf("\n");
    print_back(ptr);
}
int main()
{
    struct dll *head=create();
    int choice,l;
    char ch;
    while(1)
    {
        printf("\n1.Insert");
        printf("\n2.delete");
        printf("\n3.length");
        printf("\n4.print");
        printf("\n5.middle");
        printf("\n6.Count");
        printf("\n7.Print_Back");
        printf("\n8.Make_Random_list");
        printf("\n9.Clone_list");
        printf("\n10.exit");
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
            l=length(head);
            printf("\n%d",l);
            break;
            case 4:
            print(head);
            break;
            case 5:
            middle(head);
            break;
            case 6:
            count(head);
            break;
            case 7:
            print_back(head);
            break;
            case 8:
            make_random_list(head);
            break;
            case 9:
            clone_list(head);
            break;
            case 10:
            free(head);
            exit(0);
            break;
            default : 
            printf("\n you have entered the wrong choice  ");
            goto label;
        }
    }
    return 0;
}