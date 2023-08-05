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
// void Ordered_Insert(struct cl *ptr)
// {
//     int data;
//     struct cl *temp=(struct cl *)malloc(sizeof(struct cl));
//     printf("\n enter the data to insert: ");
//     scanf("%d",&data);
//     temp->data=data;
//     struct cl *pre=ptr,*ctr=ptr,*cur=ptr;
//     while(pre->data<data)
//     {
//         if(pre->node==ptr)
//         {
//             printf("\n enter the data again :");
//             insert(ptr);
//             return;
//         }
//         ctr=pre;
//         pre=pre->node;
//     }
//     while(cur->node!=ptr)
//     {
//         cur=cur->node;
//     }
//     if(data<(ptr->data))
//     {
//         temp->node=ptr;
//         cur->node=temp;
//         ptr=temp;
//         return;
//     }
//     ctr->node=temp;
//     temp->node=pre;
//     return;
// }
// struct cl *insert_front(struct cl *ptr)
// {
//     struct cl *pre=ptr;
//     while(pre->node!=ptr)
//     {
//         pre=pre->node;
//     }
//     struct cl *temp=(struct cl *)malloc(sizeof(struct cl));
//     int data;
//     printf("\n enter the data : ");
//     scanf("%d",&data);
//     temp->data=data;
//     temp->node=ptr;
//     pre->node=temp;
//     ptr=pre->node;
//     display(ptr);
//     return ptr;
    
// }
// struct cl *Deletion_choice(struct cl *ptr)
// {
//      int data;
//      printf("\n enter the data you want to delete : ");
//      scanf("%d",&data);
//      struct cl *pre=ptr,*ctr=ptr,*cur=ptr;
//      while(pre->node!=ptr)
//      {
//          if((pre->data)==data)
//          {
//              break;
//          }
//          ctr=pre;
//          pre=pre->node;
//      }
//      if(pre->node==ptr)
//      {
//          if((pre->data)==data)
//          {
//              ctr->node=ptr;
//              display(ctr->node);
//              return ptr;
//          }
//          else
//          {
//              printf("\n element not found to be deleted : ");
//              return ptr;
//          }
//      }
//      if((ptr->data)==data)
//      {
//            while(cur->node!=ptr)
//            {
//                cur=cur->node;
//            }
//            cur->node=ptr->node;
//            ptr=cur->node;
//            display(ptr);
//            return ptr;
//      }
//      ctr->node=pre->node;
//      display(ptr);
//      return ptr;
// }
int main()
{
    int choice;
    char ch;
    struct cl *head;
    head=create();
    do
    {
        // printf("\n1.for Insert_Front");
        printf("\n1.Insert_Rear");
        printf("\n2.for Display");
        printf("\n3.Spilit");
        // printf("\n5.Ordered Insert");
        printf("\n4.Deletion_Front");
        printf("\n5.exit");
        label:
        printf("\n enter your choice :");
        scanf("%d",&choice);
        switch(choice)
        {
            // case 1:
            // head=insert_front(head);
            // break;
            case 1: 
            head=insert_rear(head);
            break;
            case 2: 
            display(head);
            break;
            case 3:
            Split(head);
            break;
            // case 4:
            // Ordered_Insert(head);
            // break;
            case 4:
            head=Deletion_front(head);
            break;
            case 5:
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
