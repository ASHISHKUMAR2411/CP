#include<stdio.h>
#include<stdlib.h>
struct NODE
{
    int information;
    struct NODE *node;
};
void insert_(struct NODE **ptr);
void insert_btw(struct  NODE *ptr,int information);
void insert_count(struct  NODE *ptr,int count);
void insert_end(struct NODE *ptr);
void deletion_position(struct NODE **ptr,int count);
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
    printf("\n enter the index which you want to delete : ");
    scanf("%d",&q);
    deletion_position(&head,q);
    ptr=head;
    printf("\n\n\n");
    while(ptr!=NULL)
    {
        printf("\n%d",ptr->information);
        ptr=ptr->node;
    }
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
void deletion_position(struct NODE **ptr,int count)
{
    int t=0;
    struct NODE *temp,*pre;
    temp=*ptr;
    if(temp!=NULL&&count==0)
    {
        *ptr=temp->node;
        free(temp);
        return ;
    }
    while(temp!=NULL&&t!=count)
    {
        pre=temp;
        temp=temp->node;
        t++;
    }
    if(temp==NULL)
    {
        printf("\n no such element  found");
        return;
    }
    pre->node=temp->node;
    free(temp);
    
}