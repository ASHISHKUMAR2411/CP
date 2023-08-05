#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>
struct bt
{
    unsigned max;
    int size;
    int *a;
};
// the problem in this code is that we can't set which array element will be where.
// second problem is it will always show you a perfect binary tree.
struct bt *create(unsigned max);
void insert(struct bt *ptr);
void display_perfect(struct bt *ptr);
int main()
{
    struct bt *temp;
    int choice;
    unsigned max;
    printf("\n enter the value of maximum size of the array : ");
    scanf("%u",&max);
    temp=create(max);
    while(1)
    {
        printf("\n1. For Insert ");
        printf("\n2. For Display");
        printf("\n3. Exit");
        label:
        printf("\n enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            insert(temp);
            break;
        case 2:
            display_perfect(temp);
            break;
        case 3:
            free(temp);
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
struct bt *create(unsigned max)
{
    struct bt *temp=(struct bt *)malloc(sizeof(struct bt));
    temp->max=max;
    temp->size=0;
    temp->a=(int *)malloc(max * sizeof(int));
    return temp;
}
void insert(struct bt *ptr)
{
    if(ptr->size==ptr->max)
    {
        printf("\n no more space for inserting ");
        return;
    }
    int data;
    printf("\n enter the data to insert : ");
    scanf("%d",&data);
    ptr->a[ptr->size]=data;
    ptr->size += 1;
}
void display_perfect(struct bt *ptr)
{
    if(ptr==NULL)
    {
        return;
    }
    int level=0,i=0;
    for(i=1;i<=ptr->size;i++)
    {
        if(i==(pow(2,level)))
        {
            printf("\n");
            level++;
        }
        printf("%d ",ptr->a[i-1]);
    }
}