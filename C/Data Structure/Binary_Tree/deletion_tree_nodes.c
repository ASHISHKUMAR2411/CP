#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct binary_tree
{
    int info ;
    struct binary_tree *l;
    struct binary_tree *r;
};
static bool flag=false;
int height =0;
struct binary_tree **arr;
struct binary_tree *ret=NULL;
struct binary_tree *sr=NULL;
struct binary_tree *create();
void insert(struct binary_tree *ptr);
void insert_left(struct binary_tree *ptr);
void insert_right(struct binary_tree *ptr);
void display_right(struct binary_tree *ptr);
void display_left(struct binary_tree *ptr);
void display(struct binary_tree *ptr,int level);
void display_all(struct binary_tree *ptr);
void print_tabs(int number);
void print_left(struct binary_tree *ptr);
void print_right(struct binary_tree *ptr);
void search_node(struct binary_tree *ptr, int data);
void delete_node(struct binary_tree *ptr);
void rightmost_node(struct binary_tree *ptr);
struct binary_tree *root=NULL;
int main()
{
    
    int choice,l;
    int data;
    // char ch;
    struct binary_tree *pre,*ptr;
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
        printf("\n7. Delete_Node");
        printf("\n8. Search_Node");
        printf("\n9. Rightmost_Node");
        printf("\n10. Exit");
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
            delete_node(pre);
            pre=root;
            break;
            case 8:
            arr=(struct binary_tree **)malloc( height * sizeof(struct binary_tree *));
            printf("\n enter the data to be search : ");
            scanf("%d",&data);
            search_node(pre,data);
            pre=root;
            break;
            case 9:
            rightmost_node(pre);
            if(ret->r==NULL)
            {
                printf("\n%d is the rightmost value",(ret->l)->info);
                pre=root;
            }
            else
            {
                printf("\n%d is the rightmost value",(ret->r)->info);
                pre=root;
            }
            break;
            case 10:
            exit(0);
            break;
            default:
            printf("\n you have entered wrong choice : ");
            printf("\n enter again");
            goto label;
            break;
        }

    }
    free(root);
    free(pre);
    free(ptr);
    return 0;

}
struct binary_tree *create()
{
    struct binary_tree *temp=(struct binary_tree *)malloc(sizeof(struct binary_tree));
    int data;
    printf("\n enter the data you want to store on the root ");
    scanf("%d",&data);
    temp->info=data;
    temp->l=NULL;
    temp->r=NULL;
    return temp;
}
void insert(struct binary_tree *ptr)
{
    height++;
    struct binary_tree *ctr=ptr;
    int choice;
    choi:
    printf("\n enter your choice for insert :");
    printf("\n1. for left and \n2. for right \n :");
    scanf("%d",&choice);
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
void insert_left(struct binary_tree *ptr)
{
    struct binary_tree *pre=ptr;
    if(pre->l!=NULL)
    {
         insert(pre->l);
    }
    else
    {
        struct binary_tree *temp=(struct binary_tree *)malloc(sizeof(struct binary_tree));
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
void insert_right(struct binary_tree *ptr)
{
    struct binary_tree *pre=ptr;
    if(pre->r!=NULL)
    {
         insert(pre->r);
    }
    else
    {
        struct binary_tree *temp=(struct binary_tree *)malloc(sizeof(struct binary_tree));
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
void display_right(struct binary_tree *ptr)
{
   struct binary_tree *pre=ptr;
   while(pre->r!=NULL)
   {
       printf("%d ",pre->info);
       pre=pre->r;
   } 
   printf("%d ",pre->info);   
}
void display_left(struct binary_tree *ptr)
{
   struct binary_tree *pre=ptr;
   while(pre->l!=NULL)
   {
       printf("%d ",pre->info);
       pre=pre->l;
   }
   printf("%d ",pre->info);
}
void display(struct binary_tree *ptr,int level)
{
    if(ptr == NULL)
    {
        print_tabs(level);
        printf("----<empty>----\n");
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
void display_all(struct binary_tree *ptr)
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
void print_left(struct binary_tree *ptr)
{
     if(ptr->l==NULL)
     {
         printf("\n no value to display empty this side");
         return ;
     }
     else
    printf("%d\n",(ptr->l)->info);
}
void print_right(struct binary_tree *ptr)
{
    if(ptr->r==NULL)
     {
         printf("\n no value to display empty this side");
         return ;
     }
     else
    printf("%d\n",(ptr->r)->info);
}

int k=0,i=0;
void search_node(struct binary_tree *ptr, int data)
{
    if(root==NULL)
    {
        printf("\n tree is empty : ");
        return;
    }
    else
    {
        if(ptr->info==data)
        {
            flag=true;
            printf("\n the %d is found ",ptr->info);
            return;
        }
        if(flag==false && ptr->l!=NULL)
        {
            sr=ptr->l;
            search_node(sr,data);
        }
        if(flag==false && ptr->r!=NULL)
        {
            sr=ptr->r;
            search_node(sr,data);
        }

    }
    // static int count=0;
    // if(ptr->info==data)
    // {
    //     // printf("\n element found at %d level ",count);
    //     printf("\n element found ");
    //     return;
    // }
    // else if(ptr->r!=NULL && ptr->l!=NULL)
    // {
    //     // count++;
    //     // search_node(ptr->r,data);
    //     arr[i++]=ptr->r;
    //     ptr=ptr->l;
    //     search_node(ptr,data);
    // }
    // else if(ptr->r==NULL)
    // {
    //     // count++;
    //     ptr=ptr->l;
    //     search_node(ptr,data);
    // }
    // else if(ptr->l==NULL)
    // {
    //     // count++;
    //     ptr=ptr->r;
    //     search_node(ptr,data);
    // }
    // else
    // {
    //     if(i>0)
    //     {
    //         search_node(arr[--i],data);
    //     }
    //     else
    //     {
    //         printf("\n element not found ");
    //     }
    // }
    
    // return;
}
void rightmost_node(struct binary_tree *ptr)
{
    if(ptr->l==NULL && ptr->r==NULL)
    {
        return;
    }
    else if(ptr->r==NULL && ptr->l!=NULL)
    {
        ret=ptr;
        ptr=ptr->l;
        rightmost_node(ptr);
    }
    else
    {
        ret=ptr;
        ptr=ptr->r;
        rightmost_node(ptr);
    }
}
void delete_node(struct binary_tree *ptr)
{
    // here we are deleting the rightmost node and replacing that value in the position in which we want to delete
    int data;
    printf("\n Enter the node value which you want to delete : ");
    scanf("%d",&data);
    if(ptr->info==data)
    {
        ptr=ptr->r;
        return;
    }
    struct binary_tree *ctr=ptr,*pre=ptr;
    rightmost_node(ctr);
    search_node(pre,data);
    if(ret==NULL)
    {
        printf("\n No node is present at the right most ");
        return;
    } 
    if(sr==NULL)
    {
        printf("\n element not found ,\n please enter again");
        return;
    } 
    if(ret->r==NULL)
    {
        if(ret->l==pre)
        {
            ret->l==NULL;
            printf("%d element deleted ",data);
            return;
        }
    }
    if(ret->r==pre)
    {
       printf("%d element deleted ",data);
       ret->r=NULL;
       return; 
    }
    if(ret->r==NULL)
    {
        printf("\n %d element deleted and %d take its place ",sr->info,(ret->l)->info);
        sr->info=(ret->l)->info;
        ret->l=NULL;
        return;
    }
    printf("\n %d element deleted and %d take its place ",sr->info,(ret->r)->info);
    sr->info=(ret->r)->info;
    ret->r=NULL;
    return;

}