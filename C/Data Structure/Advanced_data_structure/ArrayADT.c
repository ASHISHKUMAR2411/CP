#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
struct arrayADT
{
    int maxsize;
    int size;
    int *p; //this is for int data type
};
struct arrayADT *CreateNewArrayADT(int size);
int retrieve_value_at_index(struct arrayADT *arr,int index);
void store_value_at_index(struct arrayADT *arr, int index,int value);
void modify_value_of_index(struct arrayADT *arr, int index,int new_value);
int count_no_of_values_stored(struct arrayADT *arr);
int remove_item_at_index(struct arrayADT *arr,int index);
void display_the_array(struct arrayADT *arr);
void sort_the_array(struct arrayADT *arr);
void sort_array_from_index(struct arrayADT *arr,int index);
void sort_array_before_index(struct arrayADT *arr,int index);
void sort_array_between_index(struct arrayADT *arr,int index1,int index2);
int search_value_of_index(struct arrayADT *arr,int index);
int search_value(struct arrayADT *arr,int value);
// struct arrayADT *newarray;
int main()
{
    int t,n,p,q;
    struct arrayADT *arr;
    arr=CreateNewArrayADT(15);
    for(int i=0;i<=10;i++)
    {
        scanf("%d",&t);
        store_value_at_index(arr,i,t);
    }
    n=count_no_of_values_stored(arr);
    printf("\n the total number of data stored in the array is : %d",n);
    printf("\n enter at which index you want to find the value :");
    scanf("%d",&p);
    n=retrieve_value_at_index(arr,p);
    printf("%d is found at %d index",n,p);
    n=remove_item_at_index(arr,p);
    printf("%d is found at %d index",n,p);
    display_the_array(arr);
    sort_array_before_index(arr,p);
    printf("\n enter at which index you want to find the value :");
    scanf("%d",&q);
    sort_array_between_index(arr,p,q);
    sort_array_from_index(arr,q);
    sort_the_array(arr);
    n=search_value_of_index(arr,p);
    printf("\n the searched value : %d",n);
    n=search_value(arr,n);
    printf("\n the searched value : %d",n);
    return 0;
}
struct arrayADT *CreateNewArrayADT(int size)
{
    struct arrayADT *newarray;
    newarray=(struct arrayADT *)malloc(sizeof(struct arrayADT));
    newarray->maxsize=size;
    newarray->size=-1;
    newarray->p=(int *)malloc(sizeof(int)*newarray->maxsize);
    return newarray;
}
int retrieve_value_at_index(struct arrayADT *arr ,int index)
{
    if(arr->size<index)
    {
        printf("\n no such index is available ");
        return -1;
    }
    else
    {
        return arr->p[index];
    }
}
void store_value_at_index(struct arrayADT *arr, int index,int value)
{
    if(arr->size==(arr->maxsize-1))
    {
        printf("\n you cannot store this value as because your array is full ");
    }
    else if(index<0)
    {
        printf("\n no such index is available ");
    }
    else if (index>(arr->maxsize-1))
    {
        printf("\n no such index is available ");
    }
    else if(index>(arr->size+1))
    {
        printf("\n you cannot skip the index %d ",arr->size+1);
    }
    else if(index==(arr->size+1))
    {
        arr->size = arr->size +1;
        arr->p[index]=value;
    }
    else
    {
        for(int i=arr->size;i>=index;i--)
        {
            arr->p[i+1]=arr->p[i];
        }
        arr->p[index]=value;
        arr->size=arr->size+1;
    }
}
void modify_value_of_index(struct arrayADT *arr, int index,int new_value)
{
    if(index<0)
    {
        printf("\n no such index is available ");
    }
    else if(index>(arr->size))
    {
         printf("\n cannot modify as because earlie values are not inserted ");
    }
    else
    {
        arr->p[index]=new_value;
        printf("\n modify value %d at %d ",new_value,index);
    }
}
int count_no_of_values_stored(struct arrayADT *arr)
{
    return arr->size;
}
int remove_item_at_index(struct arrayADT *arr,int index)
{
    if(index<0)
    {
        printf("\n no such index is available ");
        return -1;
    }
    else if(index>(arr->size))
    {
         printf("\n cannot delete as no values are inserted ");
         return -1;
    }  
    else if(index==arr->size)
    {
        arr->size=arr->size-1;
        return arr->p[index];
    }
    else
    {
        return arr->p[index];
        for(int i=index;i<arr->size;i++)
        {
            arr->p[i]=arr->p[i+1];
        }
        arr->size=arr->size-1;
    }
}
void display_the_array(struct arrayADT *arr)
{
    for(int i=0;i<=arr->size;i++)
    {
        printf("%d  ",arr->p[i]);
    }
}
void sort_the_array(struct arrayADT *arr)
{
    int temp;
    for(int i=0;i<arr->size;i++)
    {
        for(int j=0;j<arr->size;i++)
        {
            if(arr->p[j]>arr->p[i+1])
            {
                temp=arr->p[j];
                arr->p[i]=arr->p[i+1];
                arr->p[i+1]=temp;
            }
        }
    }
    printf("\n the sorted array will be ");
    for(int i=0;i<=arr->size;i++)
    {
        printf("%d  ",arr->p[i]);
    }
}
void sort_array_from_index(struct arrayADT *arr,int index)
{
    if(index>=0&&index<=arr->size)
    { 
        int temp;
        for(int i=index;i<arr->size;i++)
        {
            for(int j=0;j<arr->size;i++)
            {
               if(arr->p[j]>arr->p[i+1])
               {
                  temp=arr->p[j];
                   arr->p[i]=arr->p[i+1];
                  arr->p[i+1]=temp;
               }
            }
        }
        printf("\n the sorted array will be ");
        for(int i=0;i<=arr->size;i++)
        {
            printf("%d  ",arr->p[i]);
        }
    }
    else
    {
        printf("\n wrong index is given ");
    } 
}
void sort_array_before_index(struct arrayADT *arr,int index)
{
    if(index>=0&&index<=arr->size)
    { 
        int temp;
        for(int i=0;i<index;i++)
        {
            for(int j=0;j<index;i++)
            {
               if(arr->p[j]>arr->p[i+1])
               {
                  temp=arr->p[j];
                   arr->p[i]=arr->p[i+1];
                  arr->p[i+1]=temp;
               }
            }
        }
        printf("\n the sorted array will be ");
        for(int i=0;i<=arr->size;i++)
        {
            printf("%d  ",arr->p[i]);
        }
    }
    else
    {
        printf("\n wrong index is given ");
    } 
}
void sort_array_between_index(struct arrayADT *arr,int index1,int index2)
{
    if(index1>=0  && index2>=0 && index1<=arr->size && index2<=arr->size)
    { 
        int temp;
        for(int i=index1;i<index2;i++)
        {
            for(int j=index1;j<index2;i++)
            {
               if(arr->p[j]>arr->p[i+1])
               {
                  temp=arr->p[j];
                   arr->p[i]=arr->p[i+1];
                  arr->p[i+1]=temp;
               }
            }
        }
        printf("\n the sorted array will be ");
        for(int i=0;i<=arr->size;i++)
        {
            printf("%d  ",arr->p[i]);
        }
    }
    else
    {
        printf("\n wrong index is given ");
    } 
}
int search_value_of_index(struct arrayADT *arr,int index)
{
    if(index>=0&&index<=arr->size)
    { 
        return arr->p[index];
    }
    else
    {
        printf("\n wrong index is given ");
        return -1;
    } 
}
int search_value(struct arrayADT *arr,int value)
{
    for(int i=0;i<=arr->size;i++)
    {
        if(arr->p[i]==value)
        {
            return i;
            break;
        }
    }
    return -1; 
}