#include <stdio.h>
#include <stdlib.h>
struct ll
{
    int flag;
    int data;
    struct ll *next;
};
struct ll *create()
{
    int data;
    struct ll *temp = (struct ll *)malloc(sizeof(struct ll));
    printf("\n enter the data ");
    scanf("%d", &data);
    temp->data = data;
    temp->flag = 0;
    temp->next = NULL;
    return temp;
}
void insert(struct ll *ptr)
{
    struct ll *pre;
    while (ptr != NULL)
    {
        pre = ptr;
        ptr = ptr->next;
    }
    int data;
    struct ll *temp = (struct ll *)malloc(sizeof(struct ll));
    printf("\n enter the data : ");
    scanf("%d", &data);
    temp->data = data;
    temp->flag = 0;
    temp->next = NULL;
    pre->next = temp;
}
void deletion(struct ll *ptr)
{
    int pos, count = 0;
    struct ll *pre;
    printf("enter the position to delete : ");
    scanf("%d", &pos);
    while (ptr != NULL && count < pos)
    {
        pre = ptr;
        count++;
        ptr = ptr->next;
    }
    pre->next = ptr->next;
}
int length(struct ll *ptr)
{
    struct ll *pre=ptr;
    int count = 0;
    while (pre != NULL)
    {
        count++;
        pre = pre->next;
    }
    // printf("\n%d",count);
    return count;
}
void print(struct ll *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
void middle(struct ll *ptr)
{
    struct ll *pre, *post;
    pre = ptr;
    post = ptr;
    // int count=0,len=length(ptr);
    while (post->next != NULL && post != NULL)
    {
        pre = pre->next;
        post = (post->next)->next;
    }
    printf("\n%d", pre->data);
}
void create_loop(struct ll *ptr)
{
    struct ll *pre;
    int n, count = 0;
    printf("\n enter the position for the creating the loop int the array : ");
    scanf("%d", &n);
    while (ptr != NULL && count < n)
    {
        count++;
        ptr = ptr->next;
    }
    pre = ptr;
    while (ptr->next = NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = pre;
}
void check_loop(struct ll *ptr)
{
    struct ll *pre, *post;
    pre = ptr;
    post = ptr;
    int count = 1;
    while (pre && post && post->next)
    {
        pre = pre->next;
        post = (post->next)->next;
        if (pre == post)
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
    struct ll *pre = ptr;
    int *a;
    // in this we are storing values in the array and then finding the palindrome
    int count = 0;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    a = (int *)malloc(count * sizeof(int));
    count = 0;
    while (pre != NULL)
    {
        a[count++] = pre->data;
        pre = pre->next;
    }
    for (int i = 0; i < (count / 2); i++)
    {
        if (a[i] == a[count - 1 - i])
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
    return;
}
void duplicate(struct ll *ptr)
{
    struct ll *pre = ptr, *dummy = ptr, *post = ptr, *a = ptr;
    while (ptr != NULL)
    {
        pre = ptr->next;
        while (pre != NULL)
        {
            if (pre->data == ptr->data)
            {
                dummy->next = ((pre->next)->next);
                pre = dummy;
            }
            dummy = pre;
            pre = pre->next;
        }
        ptr = pre;
    }
    print(post);
}
void sort(struct ll *ptr)
{
    int min = 0;
    struct ll *tmp = ptr, *pre = ptr, *post = ptr, *a = ptr;
    while (ptr != NULL)
    {
        min = ptr->data;
        pre = ptr->next;
        while (pre != NULL)
        {
            if (min > pre->data)
            {
                tmp = pre;
            }
        }
    }
}
void swap_kth_both(struct ll **ptr)
{
    struct ll *pre = *ptr, *temp = *ptr, *ctr = NULL, *atr = NULL, *btr = NULL;
    int count = 1, k;
    printf("\nenter the number K i.e the position you want to swap");
    scanf("%d", &k);
    int len = length(pre);
    if (len < k)
    {
        printf("\n you ahve entered the value of K which is greater tahn the list but we will modulus that and give you the result : ");
        k = k % len;
    }
    if (k == (len / 2) && k%2==1)
    {
        printf("\nit's the middle value so no exchange ");
        return;
    }
    while (count < k)
    {
        ctr = pre;
        pre = pre->next;
        count++;
    }
    count = 1;
    while (count < (len - k + 1))
    {
        atr = temp;
        temp = temp->next;
        count++;
    }
    if (k == 1)
    {
        atr->next = pre;
        temp->next = pre->next;
        pre->next = NULL;
        *ptr = temp;
        return;
    }
    atr->next = pre;
    ctr->next = temp;
    btr = temp->next;
    temp->next = pre->next;
    pre->next = btr;
    return;
}
int main()
{
    struct ll *head = create();
    int choice, l;
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
        printf("\n8.Palindrom");
        printf("\n9.duplicates");
        printf("\n10.sort");
        printf("\n11.Swapping_thr_kth_node_from_both_ends");
        printf("\n12.exit");
        printf("\n");
    label:
        printf("\n enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert(head);
            break;
        case 2:
            deletion(head);
            break;
        case 3:
            l = length(head);
            printf("\n%d", l);
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
            sort(head);
            break;
        case 11:
            swap_kth_both(&head);
            break;
        case 12:
            exit(0);
            break;
        default:
            printf("\n you have entered the wrong choice  ");
            goto label;
            break;
        }
    } 
    return 0;
}
