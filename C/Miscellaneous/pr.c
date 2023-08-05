#include<stdio.h>
#include <stdlib.h>
 
typedef struct 
{
    int data;
    struct AVL_node *left,*right;
    int ht;
}   AVL_node;
 
AVL_node *insert(AVL_node *ptr,int n);
void inorder(AVL_node *ptr);
int size( AVL_node *ptr);
AVL_node *rotateright(AVL_node *ptr);
AVL_node *rotateleft(AVL_node *ptr);
AVL_node *RR(AVL_node *ptr);
AVL_node *LL(AVL_node *ptr);
AVL_node *LR(AVL_node *ptr);
AVL_node *RL(AVL_node *ptr);
int BF(AVL_node *ptr);
 
int main()
{
    AVL_node *root=NULL;
    int number,n,i,option;
    while(1)
    {
        printf("\n1)Insert:");
        printf("\n2)Print:");
        printf("\n3)Quit:");
        printf("\n\nEnter Your Choice:");
        scanf("%d",&option);
        switch(option)
        {
            case 1: printf("\nEnter a data:");
                    scanf("%d",&number);
                    root=insert(root,number);
                    break;
            case 2: printf("\n\nInorder sequence:\n");
                    inorder(root);
                    printf("\n");
                    break;
            case 3: exit(0);
                    break;
            default: printf("You have given wrong input");
        }
    }
    
    return 0;
}
 
AVL_node * insert(AVL_node *T,int num)
{
    AVL_node * temp = T;
    if(temp==NULL)
    {
        temp=(AVL_node*)malloc(sizeof(AVL_node));
        temp->data=num;
        temp->left=NULL;
        temp->right=NULL;
        T = temp;
    }
    else
        if(num > temp->data) // insert in right subtree
        {
            temp->right=insert(T->right,num);
            if(BF(T)==-2)
            if(num>T->right->data)
            T=RR(T);
            else
            T=RL(T);
        }
        else
            if(num<T->data)
            {
                T->left=insert(T->left,num);
                if(BF(T)==2)
                if(num < T->left->data)
                T=LL(T);
                else
                T=LR(T);
            }
            T->ht=size(T);
    return(T);
}
 
int size(AVL_node *T)
{
    int lh,rh;
    if(T==NULL)
        return(0);
    if(T->left==NULL)
        lh=0;
    else
        lh=1+T->left->ht;
    if(T->right==NULL)
        rh=0;
    else
        rh=1+T->right->ht;
    if(lh>rh)
    return(lh);
    return(rh);
}
 
AVL_node * rotateright(AVL_node *x)
{
    AVL_node *y;
    y=x->left;
    x->left=y->right;
    y->right=x;
    x->ht=size(x);
    y->ht=size(y);
    return(y);
}
 
AVL_node * rotateleft(AVL_node *x)
{
    AVL_node *y;
    y=x->right;
    x->right=y->left;
    y->left=x;
    x->ht=size(x);
    y->ht=size(y);
    return(y);
}
 
AVL_node * RR(AVL_node *T)
{
    T=rotateleft(T);
    return(T);
}
 
AVL_node * LL(AVL_node *T)
{
    T=rotateright(T);
    return(T);
}
 
AVL_node * LR(AVL_node *T)
{
    T->left=rotateleft(T->left);
    T=rotateright(T);
    return(T);
}
 
AVL_node * RL(AVL_node *T)
{
    T->right=rotateright(T->right);
    T=rotateleft(T);
    return(T);
}
 
int BF(AVL_node *T)
{
    int lh,rh;
    if(T==NULL)
        return(0);
    
    if(T->left==NULL)
        lh=0;
    else
        lh=1+T->left->ht;
    
        if(T->right==NULL)
            rh=0;
        else
            rh=1+T->right->ht;
    
    return(lh-rh);
}
 
void inorder(AVL_node *T)
{
if(T!=NULL)
{
inorder(T->left);
printf("%d(Bf=%d)",T->data,BF(T));
inorder(T->right);
}
}