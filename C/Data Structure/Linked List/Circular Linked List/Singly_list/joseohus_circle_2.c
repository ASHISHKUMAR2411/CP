//  in this we will see how we can we can create the singly list nd make a circular linked lists and queue for deletion

#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<string.h>
struct cl
{
    int data;
    struct cl *node;
};
struct cl *create()
{
    int data;
    struct cl *temp=(struct cl *)malloc(sizeof(struct cl));
    printf("\n enter the data ");
    scanf("%d",&data);
    temp->data=data;
    temp->node=temp;
    return temp;
}
struct cl *insert_rear(struct cl *ptr)
{
    int data;
    struct cl *pre=ptr;
    while(pre->node!=ptr)
    {
        pre=pre->node;
    }
    struct cl *temp=(struct cl *)malloc(sizeof(struct cl));
    printf("\n enter the data you want to insert  : ");
    scanf("%d",&data);
    temp->data=data;
    pre->node=temp;
    temp->node=ptr;
    return ptr;
}
void display(struct cl *ptr)
{
    struct cl *ctr=ptr;
    printf("\n");
    if(ptr->node==ptr)
    {
        printf("%d ",ptr->data);
        return;
    }
    while(ctr->node!=ptr)
    {
        printf("%d ",ctr->data);
        ctr=ctr->node;
    }
    printf("%d ",ctr->data);
    return;
}
void Split(struct cl *ptr)
{
    struct cl *pre=ptr,*fast=ptr,*temp=NULL,*prev,*fas;
    if(ptr->node==ptr)
    {
        printf("\n cannot spilit ");
        return;
    }
    while((fast->node)->node!=ptr  && fast->node!=ptr)
    {
        pre=pre->node;
        fast=(fast->node)->node;
    }
    temp=pre->node;
    pre->node=ptr;
    display(pre->node);
    if(fast->node==ptr)
    {
        fast->node=temp;
        display(fast->node);
        fast->node=ptr;
        pre->node=temp;
    }
    else if((fast->node)->node==ptr)
    {
        (fast->node)->node=temp;
        display((fast->node)->node);
        (fast->node)->node=ptr;
        pre->node=temp;
    }

    return;

}
struct cl *Deletion_front(struct cl *ptr)
{
    struct cl *ctr=ptr,*temp=ptr;
    if(ptr->node==ptr)
    {
        printf("\n %d is deleted ",ptr->data);
        ptr=NULL;
        return ptr;
    }
    else
    {
        // temp=ptr->node;
        while(ctr->node!=ptr)
        {
            ctr=ctr->node;
        }
        ctr->node=ptr->node;
        ptr=ctr->node;
        return ptr;
    }
}
struct cl *insert_front(struct cl *ptr)
{
    struct cl *pre=ptr;
    while(pre->node!=ptr)
    {
        pre=pre->node;
    }
    struct cl *temp=(struct cl *)malloc(sizeof(struct cl));
    int data;
    printf("\n enter the data : ");
    scanf("%d",&data);
    temp->data=data;
    temp->node=ptr;
    pre->node=temp;
    ptr=pre->node;
    display(ptr);
    return ptr;
    
}
void Ordered_Insert(struct cl *ptr)
{
    // here are inserting in decreasing  order
    int info;
    struct cl *temp=(struct cl *)malloc(sizeof(struct cl));
    printf("\n enter the data to insert: ");
    scanf("%d",&info);
    temp->data=info;
    struct cl *pre=ptr,*ctr=ptr,*cur=ptr;
    while((pre->data) < info)
    {
        if(pre->node==ptr)
        {
            printf("\n enter the data again :");
            ptr=insert_front(ptr);
            return;
        }
        ctr=pre;
        pre=pre->node;
    }
    while(cur->node!=ptr)
    {
        cur=cur->node;
    }
    if(info<(ptr->data))
    {
        temp->node=ptr;
        cur->node=temp;
        ptr=temp;
        return;
    }
    ctr->node=temp;
    temp->node=pre;
    return;
}
struct cl *Deletion_choice(struct cl *ptr)
{
     int data;
     printf("\n enter the data you want to delete : ");
     scanf("%d",&data);
     struct cl *pre=ptr,*ctr=ptr,*cur=ptr;
     while(pre->node!=ptr)
     {
         if((pre->data)==data)
         {
             break;
         }
         ctr=pre;
         pre=pre->node;
     }
     if(pre->node==ptr)
     {
         if((pre->data)==data)
         {
             ctr->node=ptr;
             display(ctr->node);
             return ptr;
         }
         else
         {
             printf("\n element not found to be deleted : ");
             return ptr;
         }
     }
     if((ptr->data)==data)
     {
           while(cur->node!=ptr)
           {
               cur=cur->node;
           }
           cur->node=ptr->node;
           ptr=cur->node;
           display(ptr);
           return ptr;
     }
     ctr->node=pre->node;
     display(ptr);
     return ptr;
}
int count_node(struct cl *ptr)
{
    struct cl *ctr=ptr;
    printf("\n");
    int count =0;
    if(ptr->node==ptr)
    {
        count=1;
        printf("%d Node are present ",count);
        return;
    }
    count++;
    while(ctr->node!=ptr)
    {
        count++;
        ctr=ctr->node;
    }
    printf("%d Nodes are present  ",count);
    return count;
}
void josephus_circle(struct cl *ptr)
{
    // in this we will try to skip k-1 element and delete the kth element and we have to chose the posititon so that we find ourselves in the postion till the end  
    // simple implementation 
    int n=count_node(ptr);
    int k;
    printf("\n enter the kth position you want to kill :");
    scanf("%d",&k);
    int pos=position(n,k);
    printf("\n the safe positon for josephus circle is %d",pos);
}
int position(int n,int k)
{
    if(n==1)
    {
        return 1;

    }
    else
    {
        return (position(n-1,k)+k-1)%n+1;
    }
}
void josephus_circle2(struct cl *ptr)
{
    // pending
}
int main()
{
            int len;

    int choice;
    char ch;
    struct cl *head;
    head=create();
    do
    {
        printf("\n1.for Insert_Front");
        printf("\n2.Insert_Rear");
        printf("\n3.for Display");
        printf("\n4.Spilit");
        printf("\n5.Ordered Insert");
        printf("\n6.Deletion_Front");
        printf("\n7.Deletion_choice");
        printf("\n8.Count_Nodes");
        printf("\n9.Josephus_Circle");
        printf("\n10.exit");
        label:
        printf("\n enter your choice :");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            head=insert_front(head);
            break;
            case 2: 
            head=insert_rear(head);
            break;
            case 3: 
            display(head);
            break;
            case 4:
            Split(head);
            break;
            case 5:
            Ordered_Insert(head);
            break;
            case 6:
            head=Deletion_front(head);
            break;
            case 7:
            head=Deletion_choice(head);
            break;
            case 8:
            len=count_node(head);
            break;
            case 9:
            josephus_circle(head);
            break;
            case 10:
            free(head);
            exit(0);
            break;
            default: 
            printf("\n Wrong Choice ");
            printf("\n enter your choice again : ");
            goto label;
        }
        printf("\n Do you want to perform more options : ");
        scanf("%c",&ch);
        scanf("%c",&ch);
    } while (ch=='y'||ch=='Y');
    return 0;
}
