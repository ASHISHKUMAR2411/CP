#include<stdio.h>
#include<stdlib.h>
struct bt
{
    int info ;
    struct bt *l;
    struct bt *r;
};
struct bt *create();
void insert(struct bt *ptr);
void insert_left(struct bt *ptr);
void insert_right(struct bt *ptr);
void display_right(struct bt *ptr);
void display_left(struct bt *ptr);
void display(struct bt *ptr,int level);
void display_all(struct bt *ptr);
void print_tabs(int number);
void print_left(struct bt *ptr);
void print_right(struct bt *ptr);
int main()
{
    int choice,l;
    // char ch;
    struct bt *root,*pre,*ptr;
    root=create();
    pre=root;
    ptr=root;
    while(1)
    {
        printf("\n1. Insert");
        printf("\n2. Display_Only_Right");
        printf("\n3. Display_Only_Left");
        printf("\n4. Display_Left");
        printf("\n5. Display_Right");
        printf("\n6. Display_All");
        printf("\n7. Exit");
        label:
        printf("\n enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            insert(ptr);
            ptr=root;
            break;
            case 2:
            display_right(root);
            break;
            case 3:
            display_left(root);
            break;
            case 4:
            print_left(root);
            break;
            case 5:
            print_right(root);
            break;
            case 6:
            display_all(root);
            break;
            case 7:
            exit(0);
            break;
            default:
            printf("\n you have entered wrong choice : ");
            printf("\n enter again");
            goto label;
            break;
        }

    }
    return 0;

}
struct bt *create()
{
    struct bt *temp=(struct bt *)malloc(sizeof(struct bt));
    int data;
    printf("\n enter the data you want to store on the root ");
    scanf("%d",&data);
    temp->info=data;
    temp->l=NULL;
    temp->r=NULL;
    return temp;
}
void insert(struct bt *ptr)
{
    struct bt *ctr=ptr;
    int choice;
    choi:
    printf("\n enter your choice for insert :");
    printf("\n1. for left and \n2. for right \n :");
    scanf("%d",choice);
    switch(choice)
    {
        case 1:
        insert_left(ctr);
        break;
        case 2:
        insert_right(ctr);
        break;
        default:
        printf("\n wrong choice :");
        goto choi;
        break;
    }
}
void insert_left(struct bt *ptr)
{
    struct bt *pre=ptr;
    if(pre->l!=NULL)
    {
         insert(pre->l);
    }
    else
    {
        struct bt *temp=(struct bt *)malloc(sizeof(struct bt));
        if(temp!=NULL)
        {
            int data;
            printf("\n enter the data you want to insert : ");
            scanf("%d",&data);
            temp->info=data;
            temp->l=NULL;
            temp->r=NULL;
            pre->l=temp;
            return;
        }
        else
        {
            printf("\n meemory not allocated for insertion ");
            return;
        }
    }
}
void insert_right(struct bt *ptr)
{
    struct bt *pre=ptr;
    if(pre->r!=NULL)
    {
         insert(pre->r);
    }
    else
    {
        struct bt *temp=(struct bt *)malloc(sizeof(struct bt));
        if(temp!=NULL)
        {
            int data;
            printf("\n enter the data you want to insert : ");
            scanf("%d",&data);
            temp->info=data;
            temp->l=NULL;
            temp->r=NULL;
            pre->r=temp;
            return;
        }
        else
        {
            printf("\n meemory not allocated for insertion ");
            return;
        }
    }
}
void display_right(struct bt *ptr)
{
   struct bt *pre=ptr;
   while(pre->r!=NULL)
   {
       printf("%d ",pre->info);
       pre=pre->r;
   } 
   printf("%d ",pre->info);   
}
void display_left(struct bt *ptr)
{
   struct bt *pre=ptr;
   while(pre->l!=NULL)
   {
       printf("%d ",pre->info);
       pre=pre->l;
   }
   printf("%d ",pre->info);
}
void display(struct bt *ptr,int level)
{
    if(ptr == NULL)
    {
        print_tabs(level);
        printf("----<empty>----");
        return;
    }
    print_tabs(level);
    printf(" Value = %d\n",ptr->info);
    print_tabs(level);
    printf("left\n");
    display(ptr->l,level+1);
    print_tabs(level);
    printf("right\n");
    display(ptr->r,level+1);
    print_tabs(level);
    printf("done\n");
}
void display_all(struct bt *ptr)
{
    display(ptr,0);
}
void print_tabs(int number)
{
    for(int i=0;i<number;i++)
    {
        printf("\t");
    }
}
void print_left(struct bt *ptr)
{
     if(ptr->l==NULL)
     {
         printf("\n no value to display empty this side");
         return ;
     }
     else
    printf("%d\n",(ptr->l)->info);
}
void print_right(struct bt *ptr)
{
    if(ptr->r==NULL)
     {
         printf("\n no value to display empty this side");
         return ;
     }
     else
    printf("%d\n",(ptr->r)->info);
}