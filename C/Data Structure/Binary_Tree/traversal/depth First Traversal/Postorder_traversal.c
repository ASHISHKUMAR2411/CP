#include<stdio.h>
#include<stdlib.h>
struct binary_tree
{
    int info ;
    struct binary_tree *l;
    struct binary_tree *r;
};
// this method is taking O(n) time complexity and printing the breadth-wise 
// in this we are traversing through the postorder traversal(left,right,root)
struct binary_tree *root=NULL;
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
void breadth_traversal(struct binary_tree *ptr);
void printGivenLevel(struct binary_tree *ptr,int level);
void printGivenOrder(struct binary_tree *ptr);
int height(struct binary_tree *ptr);
void preorder_traversal(struct binary_tree *ptr);
void postorder_traversal(struct binary_tree *ptr);
void inorder_traversal(struct binary_tree *ptr);

int main()
{
    int choice,l;
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
        printf("\n7. Breadth_Traversal");
        printf("\n8. Exit");
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
            printf("\n the given order traversal : ");
            printGivenOrder(root);
            break;
            case 8:
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
void breadth_traversal(struct binary_tree *ptr)
{
    
}
void printGivenLevel(struct binary_tree *ptr,int level)
{
    if(ptr==NULL)
    {
        return;
    }
    if(level==1)
    {
        printf("%d ",ptr->info);
    }
    else if(level>1)
    {
        // printf("\t");
        printGivenLevel(ptr->l,level-1);
        printf("\t");
        printGivenLevel(ptr->r,level-1);
    }
}
void printGivenOrder(struct binary_tree *ptr)
{
      int h=height(ptr);
      int i;
      for( i=1;i<=h;i++)
      {
          printf("\n");
        printGivenLevel(ptr,i);
      }
}
int height(struct binary_tree *ptr)
{
    if(ptr==NULL)
    {
        return 0;
    }
    else
    {
        int lh=height(ptr->l);
        int rh=height(ptr->r);
        if(lh>rh)
        {
            return (lh+1);
        }
        else
        {
            return (rh+1);
        }
    }
}
void preorder_traversal(struct binary_tree *ptr)
{
    if(ptr==NULL)
    {
        return;
    }
    printf("%d ",ptr->info);
    preorder_traversal(ptr->l);
    preorder_traversal(ptr->r);
}
void postorder_traversal(struct binary_tree *ptr)
{
    if(ptr==NULL)
    {
        return;
    }
    postorder_traversal(ptr->l);
    postorder_traversal(ptr->r);
    printf("%d ",ptr->info);
}
void inorder_traversal(struct binary_tree *ptr)
{
    if(ptr==NULL)
    {
        return;
    }
    inorder_traversal(ptr->l);
    printf("%d ",ptr->info);
    inorder_traversal(ptr->r);
}