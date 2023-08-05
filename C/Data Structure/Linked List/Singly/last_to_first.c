// can also be used in sorted linked list
#include<stdio.h>
#include<stdlib.h>
struct ll
{
    int flag;
    int data ;
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
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
void middle(struct ll *ptr)
{
    struct ll *pre,*post;
    pre=ptr;
    post=ptr;
    // int count=0,len=length(ptr);
    while(post->next!=NULL && post!=NULL)
    {
        pre=pre->next;
        post=(post->next)->next;
    }
    printf("\n%d",pre->data);
}
void create_loop(struct ll *ptr)
{
    struct ll *pre;
    int n,count=0;
    printf("\n enter the position for the creating the loop int the array : ");
    scanf("%d",&n);
    while(ptr!=NULL && count<n)
    {
        count++;
        ptr=ptr->next;
    }
    pre=ptr;
    while(ptr->next=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=pre;
}
void check_loop(struct ll *ptr)
{
    struct ll *pre,*post;
    pre=ptr;
    post=ptr;
    int count =1;
    while(pre && post && post->next)
    {
        pre=pre->next;
        post=(post->next)->next;
        if(pre==post)
        {
            printf("\n yes loop");
            return;
        }
    }
    printf("\n No");
    return;
}
void palindrom(struct ll *ptr)
{
    struct ll *pre=ptr;
    int *a;
    // in this we are storing values in the array and then finding the palindrome
    int count =0;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->next;
    }
    a=(int *)malloc(count*sizeof(int));
    count=0;
    while(pre!=NULL)
    {
        a[count++]=pre->data;
        pre=pre->next;
    }
    for(int i=0;i<(count/2);i++)
    {
        if(a[i]==a[count-1-i])
        {
            continue;
        }
        else
        {
            printf("\n not palindrom : ");
            return;
        }
    }
    printf("\n palindrom");
    return ; 
}
void duplicate(struct ll *ptr)
{
    int *a,l=0,i=0,j,count=0;
    struct ll *pre=ptr,*dummy;
    l=length(ptr);
    a=(int *)malloc(l*sizeof(int));
    while(ptr!=NULL&&ptr->next!=NULL)
    {
        
        a[i]=ptr->data;
        for(int j=0;j<i;j++)
        {
            if(a[i]==a[j])
            {
                dummy->next=((ptr->next));
                ptr=dummy;                
            }
        }
        dummy=ptr;
        i++;
        ptr=ptr->next;
    }
    print(pre);
}
void swap_pair(struct ll *ptr)
{
    struct ll *pre=ptr;
    int temp;
    if(ptr && ptr->next)
        {
            temp=ptr->data;
            ptr->data=(ptr->next)->data;
            (ptr->next)->data=temp;
            ptr=(ptr->next)->next;
            swap_pair(ptr);
        }
    return;

}
void last_first(struct ll *ptr)
{
    struct ll *pre=ptr,*prev=ptr,*temp;
    while(ptr->next!=NULL)
    {
        prev=ptr;
        ptr=ptr->next;
    }
    prev->next=NULL;
    temp=ptr;
    temp->next=pre;
    // pre=temp;
    print(temp);

}

int main()
{
    struct ll *head=create();
    int choice,l;
    char ch;
    do
    {
        printf("\n1.Insert");
        printf("\n2.delete");
        printf("\n3.length");
        printf("\n4.print");
        printf("\n5.middle");
        printf("\n6.Loop");
        printf("\n7.Check-loop");
        printf("\n8.Palindrom");
        printf("\n9.duplicates");
        printf("\n10.swap_pair");
        printf("\n11.last_first");
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
            palindrom(head);
            break;
            case 9:
            duplicate(head);
            break;
            case 10:
            swap_pair(head);
            break;
            case 11:
            last_first(head);
            break;
            case 12:
            exit(0);
            break;
            default : 
            printf("\n you have entered the wrong choice  ");
            goto label;
            break;
        }
        printf("\n enter y/Y for more operation : ");
        scanf("%c",&ch);
        scanf("%c",&ch);
    } while (ch=='y'||ch=='Y');
    return 0;
}
