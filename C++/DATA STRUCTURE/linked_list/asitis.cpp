#include <stdio.h>
#include <stdlib.h>
struct ll
{
    char name[10];
    struct ll *next;
};
// 1 + (rand () % 6)
struct ll *create()
{
    struct ll *temp = (struct ll *)malloc(sizeof(struct ll));
    printf("\n enter the 1st  name ");
    gets(temp->name);
    temp->next = NULL;
    return temp;
}
void insert(struct ll *ptr)
{
    static int count = 1;
    count++;
    struct ll *pre;
    while (ptr != NULL)
    {
        pre = ptr;
        ptr = (ptr)->next;
    }
    struct ll *temp = (struct ll *)malloc(sizeof(struct ll));
    printf("\n enter the %d name  : ", count);
    gets(temp->name);
    temp->next = NULL;
    pre->next = temp;
    while (count < 20)
    {
        insert(ptr);
    }
}
void deletion_position(struct ll **ptr, int count)
{
    if (count == 1)
    {
        printf("\n%s is the winner", (*ptr)->name);
        exit(0);
    }
    int t = 0;
    int position = 1 + (rand() % 6);
    struct ll *temp, *pre;
    temp = *ptr;
    if (temp != NULL && position == 0)
    {
        printf("\n %s is out ", temp->name);
        *ptr = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && t != position)
    {
        pre = temp;
        temp = temp->next;
        t++;
    }
    if (temp == NULL)
    {
        printf("\n no such element  found");
        return;
    }
    printf("\n %s is out ", temp->name);
    pre->next = temp->next;
    free(temp);
    count--;
    deletion_position(ptr, count);
}
void print(struct ll *ptr)
{
    struct ll *pre = ptr;
    while (pre != NULL)
    {
        printf("%s ", pre->name);
        pre = pre->next;
    }
}
int main()
{
    struct ll *head = create();
    int choice, l;
    char ch;
    while (1)
    {
        printf("\n1.Insert Names in the List ");
        printf("\n2.Start The Game ");
        printf("\n3.Display The List ");
        printf("\n4.Display The List ");
        printf("\n");
    label:
        printf("\n enter your choice : ");
        scanf("%d", &choice);
        scanf("%c", &ch);
        switch (choice)
        {
        case 1:
            insert(head);
            break;
        case 2:
            deletion_position(&head, 20);
            break;
        case 3:
            print(head);

            break;
        case 4:
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
