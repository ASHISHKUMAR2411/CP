#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct NODE
{
    int information;
    struct NODE *node;
};
void insert_(struct NODE **ptr);
void insert_btw(struct  NODE *ptr,int information);
void insert_count(struct  NODE *ptr,int count);
void insert_end(struct NODE *ptr);
void deletion(struct NODE **ptr,int item);
void length_list(struct NODE *ptr);
int  length_l(struct NODE *ptr);
void search(struct NODE *ptr,int item);
bool searching(struct NODE *ptr,int item);
int  getnode(struct NODE *ptr,int position);
int GetNodeFromLast(struct NODE *ptr,int position);
int getNODE_Method2fromEnd(struct NODE *ptr,int position);
int main()
{
    int n,m,p,q,information,count=0;
    struct NODE *head,*ptr,*temp=NULL;
    head=(struct NODE *)malloc(sizeof(struct NODE));
    scanf("%d",&n);
    head->information=n;
    head->node=NULL;
    printf("\n enter how many item you want o insert :");
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        insert_(&head);
    }
    ptr=head;
    printf("\n\n\n");
    while(ptr!=NULL)
    {
        printf("\n%d",ptr->information);
        ptr=ptr->node;
    }

    printf("\n enter the informationn after which you want to insert :");
    scanf("%d",&p);
    ptr=head;
    printf("\n\n\n");
    do
    {
        if(ptr->information==p)
        {
           insert_btw(ptr,p);
        }
        ptr=ptr->node;
    } while (ptr!=NULL);

    ptr=head;
    while(ptr!=NULL)
    {
        printf("\n%d",ptr->information);
        ptr=ptr->node;
    }
    ptr=head;
    n=length_l(ptr);
    printf("\n th elength is : %d",n);
    ptr=head;
    printf("\n\n\n");
    while(ptr!=NULL)
    {
        printf("\n%d",ptr->information);
        ptr=ptr->node;
    }
    printf("\n enter the index after which you want to insert : ");
    scanf("%d",&q);
    ptr=head;
    do
    {
        if(count==q)
        {
            insert_count(ptr,q);
        }
        ptr=ptr->node;
        count++;
    } while (ptr!=NULL);
    ptr=head;
    printf("\n\n\n");
    while(ptr!=NULL)
    {
        printf("\n%d",ptr->information);
        ptr=ptr->node;
    }
    ptr=head;
    while(ptr->node!=NULL)
    {
        ptr=ptr->node;
    }
    insert_end(ptr);
    ptr=head;
    printf("\n\n\n");
    while(ptr!=NULL)
    {
        printf("\n%d",ptr->information);
        ptr=ptr->node;
    }
    printf("\n enter the elment which you want to delete : ");
    scanf("%d",&q);
    deletion(&head,q);
    ptr=head;
    printf("\n\n\n");
    while(ptr!=NULL)
    {
        printf("\n%d",ptr->information);
        ptr=ptr->node;
    }
    ptr=head;
    length_list(ptr);
    ptr=head;
    printf("\n\n\n");
    while(ptr!=NULL)
    {
        printf("\n%d",ptr->information);
        ptr=ptr->node;
    }
    printf("\n enter the elment which you want to search: ");
    scanf("%d",&q);
    ptr=head;
    search(ptr,q);
    ptr=head;
    printf("\n enter the position which you want to search: ");
    scanf("%d",&q);
    n=getnode(ptr,q);
    if(n==-1)
    {
        printf("\n element not found : ");
    }
    printf("\n the value at that positin is : %d",n);
    ptr=head;
    printf("\n enter the position which you want to search from last: ");
    scanf("%d",&q);
    n=GetNodeFromLast(ptr,q);
    if(n==-1)
    {
        printf("\n no such index  found : ");
    }
    printf("\n the value at that positin is : %d",n); 
    ptr=head;
    printf("\n enter the position which you want to search from last: ");
    scanf("%d",&q);
    n=getNODE_Method2fromEnd(ptr,q);
    if(n==-1)
    {
        printf("\n no such index  found : ");
    }
    printf("\n the value at that positin is : %d",n);
    return 0;
}
void insert_(struct NODE **ptr)
{
    int temp;
    struct NODE *new=(struct NODE *)malloc(sizeof(struct NODE));
    printf("\n enter the information to be added : ");
    scanf("%d",&temp);
    new->information=temp;
    new->node=*ptr;
    *ptr=new;
}
void insert_btw(struct  NODE *ptr,int information)
{
    if(ptr==NULL)
    {
        printf("\n pointer can not be null");
        return;
    }
    int temp;
    struct NODE *new=(struct NODE *)malloc(sizeof(struct NODE));
    printf("\n enter the information to be added : ");
    scanf("%d",&temp);
    new->information=temp;
    new->node=ptr->node;
    ptr->node=new;
    
}
void insert_count(struct  NODE *ptr,int count)
{
    if(ptr==NULL)
    {
        printf("\n pointer can not be null");
        return;
    }
    int temp,n=0;
    struct NODE *new=(struct NODE *)malloc(sizeof(struct NODE));
    printf("\n enter the information to be added : ");
    scanf("%d",&temp);
    new->information=temp;
    new->node=ptr->node;
    ptr->node=new;
}
void insert_end(struct NODE *ptr)
{
    int temp,n=0;
    struct NODE *new=(struct NODE *)malloc(sizeof(struct NODE));
    printf("\n enter the information to be added : ");
    scanf("%d",&temp);
    new->information=temp;
    new->node=NULL;
    ptr->node=new;
}
void deletion(struct NODE **ptr,int item)
{
    struct NODE *temp,*pre;
    temp=*ptr;
    if(temp!=NULL&&temp->information==item)
    {
        *ptr=temp->node;
        free(temp);
        return ;
    }
    while(temp!=NULL&&temp->information!=item)
    {
        pre=temp;
        temp=temp->node;
    }
    if(temp==NULL)
    {
        printf("\n no such element  found");
        return;
    }
    pre->node=temp->node;
    free(temp);
}
void length_list(struct NODE *ptr)
{
    int count=0;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->node;
    }
    printf("\n the number of element is : %d",count);
}
int  length_l(struct NODE *ptr)
{
    if(ptr==NULL)
    {
        return 0;
    }
    return 1+length_l(ptr->node);
}
void search(struct NODE *ptr,int item)
{
    int index=0;
    while(ptr!=NULL)
    {
        index++;
        if(ptr->information==item)
        {
            printf("\n element found at %d position ",index);
            return;
        }
        ptr=ptr->node;
    }
    printf("\n OPPS element not found ");
}
bool searching(struct NODE *ptr,int item)
{
    while(ptr!=NULL)
    {
        if(ptr->information==item)
        {
            return true;
        }
    }
    return false;
}
int  getnode(struct NODE *ptr,int position)
{
    int index=0;
    while(ptr!=NULL)
    {
        if(index==position)
        {
            return ptr->information;
        }
        index++;
        ptr=ptr->node;
    }
    return -1;
}
int GetNodeFromLast(struct NODE *ptr,int position)
{
    struct NODE *temp=ptr;
    int l,m,index=0;
    l=length_l(temp);
    m=l-position;
    while(ptr!=NULL)
    {
        if(m==index)
        {
            return ptr->information;
        }
        index++;
        ptr=ptr->node;
    }
    return -1;
}
int getNODE_Method2fromEnd(struct NODE *ptr,int position)
{
    struct NODE *forward,*backward,*pre;
    forward=ptr;
    backward=ptr;
    int index=0;
    while(index!=position)
    {
        forward=forward->node;
        ptr=ptr->node;
        index++;
    }
    while(ptr!=NULL)
    {
        pre=ptr;
        forward=forward->node;
        ptr=ptr->node;
        backward=backward->node;
        
    }
    if(position==0)
    {
        return pre->information;
    }
    if(backward==NULL)
    {
        return -1;
    }
    backward=backward->node;
    if(backward==NULL)
    {
        return -1;
    }
    return backward->information;
}
