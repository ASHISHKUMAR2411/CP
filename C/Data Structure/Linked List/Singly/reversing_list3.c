#include<stdio.h>
#include<stdlib.h>
struct ll
{
    int data ,flag;
    struct ll *next;
};
struct ll *create()
{
    int data;
    struct ll *temp=(struct ll *)malloc(sizeof(struct ll));
    printf("\n enter the data ");
    scanf("%d",&data);
    temp->data=data;
    temp->flag=0;
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
    temp->flag=0;
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
int length(struct ll *ptr)
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
void print(struct ll *ptr)
{
    struct ll *pre=ptr;
    while(pre!=NULL)
    {
        if(pre->next==ptr)
        {
            printf("\n loop is present : ");
            return;
        }
        printf("%d ",pre->data);
        pre=pre->next;
    }
}
void middle(struct ll *ptr)
{
    struct ll *pre=ptr,*post=ptr;
    while(post->next!=NULL && post!=NULL)
    {
        if(pre->next==ptr || post->next==ptr)
        {
            printf("\n loop is present ");
            return;
        }
        pre=pre->next;
        post=((post->next)->next);
    }
    printf("\n%d",pre->data);
    return;
}
void create_loop(struct ll *ptr)
{
    if(ptr==NULL)
    {
        return;
    }
    struct ll *pre=ptr;
    int n,count=0;
    printf("\n enter the position for the creating the loop int the array : ");
    scanf("%d",&n);
    while(pre!=NULL && count<n)
    {
        count++;
        pre=pre->next;
    }
    pre->next=ptr;
    return;
}
void check_loop(struct ll *ptr)
{
   struct ll *pre=ptr;
   while(pre!=NULL)
   {
       if(pre->next==ptr)
       {
           printf("\n the loop is present ");
           return;
       }
       pre=pre->next;
   }
   printf("\n no loop is present : ");
   return;
}
struct ll *create_intersection(struct ll *ptr)
{
    struct ll *pre=NULL;
    if(ptr==NULL)
    {
        return pre;
    }
    int data;
    printf("\n enter the data with which you want to intersect : ");
    scanf("%d",&data);
    struct ll *a=ptr;
    while(a!=NULL)
    {
        if(a->data==data)
        {
            break;
        }
        a=a->next;
    }
    pre=(struct ll *)malloc(sizeof(struct ll));
    printf("\n enter the data you want to add : ");
    scanf("%d",&pre->data);
    pre->flag=0;
    pre->next=a;
    return pre;
}
void find_intersection(struct ll *ptr,struct ll *temp)
{
    // here we have o(n+m) time complexity but on the same tiem is also increasing space by O(n) complexity
    struct ll *pre=ptr,*cre=temp;
    while(pre!=NULL)
    {
        pre->flag++ ;
        pre=pre->next;
    }
    while(cre!=NULL)
    {
        cre->flag++;
        if(cre->flag>1)
        {
            printf("\n %d is the intersection ",cre->data);
            return ;
        }
        cre=cre->next;
    }
    // the problem is when you delete the node with which the interscetion is made then it will not recognise further as it becomes dangling 
    printf("\n no intersection :");
    return;
   
}
void segregrate_odd_even_node(struct ll **ptr)
{
    // value exchange method is not considered good as it will be good if we have only one data in that node but in real scenario there can be more than 1 data
    // we will see then also this method , thus but not able to maintain the same order
    // int his we add the odd node at the end of the linked list .



    struct ll *pre=*ptr,*curr=*ptr,*a=*ptr;
    while(pre->next!=NULL)
    {
        pre=pre->next;
    }
    struct ll *end=pre,*prev=NULL;
    while(curr!=pre && ((curr->data)%2)!=0)
    {
        end->next=curr;
        curr=curr->next;
        (end->next)->next=NULL;
        end=end->next;
    }
    if((curr->data)%2==0)
    {
        *ptr=curr;
        while(curr!=pre)
        {
            if((curr->data)%2==0)
            {
                prev=curr;
                curr=curr->next;
            }
            else
            {
                prev->next=curr->next;
                curr->next=NULL;
                end->next=curr;
                end=curr;
                curr=prev->next;
            }
        }
    }
    else
    {
        prev=curr;
    }
    if(end!=pre && ((pre->data)%2)!=0)
    {
        prev->next=pre->next;
        pre->next=NULL;
        end->next=pre;
    }

    return;
}
struct ll  *reverse(struct ll *ptr)
{
    // in this i am just reversing the order using recursive function plus we are doing only reverse the links
    // it takes O(n) time where n is the number of nodes ,
    if(ptr==NULL || ptr->next==NULL)
    {
        return ptr;
    }
    struct ll *rest=reverse(ptr->next);
    (ptr->next)->next=ptr;
    ptr->next=NULL;
    return rest;
}
int main()
{
    struct ll *head=create();
    struct ll *inter=NULL;
    int choice,l;
    char ch;
    while(1)
    {
        printf("\n1.Insert");
        printf("\n2.delete");
        printf("\n3.length");
        printf("\n4.print");
        printf("\n5.middle");
        printf("\n6.Loop");
        printf("\n7.Check-loop");
        printf("\n8.Create_intersection");
        printf("\n9.Find_Intersection");
        printf("\n10.sedrgrate_odd_even_node");
        printf("\n11.Reverse_whole_list");
        printf("\n12.exit");
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
            create_loop(head);
            break;
            case 7:
            check_loop(head);
            break;
            case 8:
            inter=create_intersection(head);
            break;
            case 9:
            find_intersection(head,inter);
            break;
            case 10:
            segregrate_odd_even_node(&head);
            break;
            case 11:
            head=reverse(head);
            break;
            case 12:
            exit(0);
            break;
            default : 
            printf("\n you have entered the wrong choice  ");
            goto label;
            break;
        }
    } 
    return 0;
}
