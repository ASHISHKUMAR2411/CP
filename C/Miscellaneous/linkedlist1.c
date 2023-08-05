// there are two ways to use linked list 
// 1. using array 
// 2.using structure(recommended)

// operation on linked list is add,delete,insert,
// using array 
#include<stdio.h>
#include<stdlib.h>
int n;
int a[50];
void input(void);
void insert(void);
void search(void);
void add(void);
void delete(void);
void display(void);
void quit(void);
int main()
{
    int n;
    char ch,b;
    printf("\n enter your choice: ");
    printf("\n1. inputs");
    printf("\n2. insert");
    printf("\n3. search");
    printf("\n4. add");
    printf("\n5. delete");
    printf("\n6. display");
    printf("\n6. quit\n");
    scanf("%d",&n);
    switch(n)
    {
        case 1: input();
        case 2: insert();
        break;
        case 3: search();
        break;
        case 4: add();
        break;
        case 5: delete();
        break;
        case 6: quit();
        break;
        default: printf("\n wrong choice");
        break;
    }
    printf("\n would you like to explore more choice press y/Y to do do :");
    scanf("%c",&b);
    scanf("%c",&ch);
    if(ch=='y'||ch=='Y')
    {
        main();
    }
    return 0;
}
void input(void)
{
    printf("\n enter the input : ");
}
void insert(void)
{
    input();
    printf("\n enter the size of the array "); 
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
void search(void)
{
    input();
    insert();
    int s;
    printf("\n enter the number you want to search in the array : ");
    scanf("%d",&s);
    for(int i=0;i<n;i++)
    {
        if(a[i]==s)
        {
            printf("element found at %d position ",i+1);
        }
    }

}
void add(void)
{
    input();
    insert();
    int b,j,k;
    printf("\n enter the number to be added : ");
    scanf("%d",&b);
    printf("\n enter the position at which you want to add : ");
    scanf("%d",&j);
    if(b>n)
    {
        printf("\n wrong position ");
    }
    else
    {
        for(int i=0;i<n+1;i++)
        {
            if(i==j)
            {
                for( k=n-1;k>=j;k--)
                {
                    a[k+1]=a[k];
                }
                a[k]=b;
            }
        }
    }

}
void delete(void)
{
    input();
    insert();
    int a,j;
    printf("\n enter the number to be deleted : ");
    scanf("%d",&a);
    printf("\n enter the position at which you want to add : ");
    scanf("%d",&j);
    if(a>n)
    {
        printf("\n wrong position ");
    }
    else
    {
        for(int i=0;i<n+1;i++)
        {
            if(i==j)
            {
                for(int k=n;k>=j;k--)
                {
                    a[k+1]=a[k];
                }
                a[k]=a;
            }
        }
    }
}
void display(void)
{
    input();
    insert();
    
   for(int i=0;i<n+1;i++)
   {
       printf("%d ",a[i]);
   }
}
void quit(void);
{
    exit(0);
}