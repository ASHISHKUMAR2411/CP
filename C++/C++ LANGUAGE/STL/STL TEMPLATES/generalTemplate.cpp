#include<bits/stdc++.h>
using namespace std;



template<class T>
int binarySearch(T arr[], T item, int low , int high)
{
    if(high<=low)
    {
        return ((item>arr[low])? (low+1): low);
    }
    int mid = (low+high)/2;
    if(item == arr[mid])
    {
        return mid+1 ;
    }
    if(item>arr[mid])
    {
        return binarySearch(arr,item,mid+1,high);
    }
    return binarySearch(arr,item,low,mid-1);
}

template<class T>
void binaryInsertionSorting(T arr[], int size)
{
    int i , j , location ;
    T selected;
    for(i= 1; i<size;i++)
    {
        j = i-1;
        selected = arr[i];
        location = binarySearch(arr,selected,0,j);
        while (j >= location)
        {
            /* code */
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1]=selected;
    }
}

template<class T>
void print(T arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}