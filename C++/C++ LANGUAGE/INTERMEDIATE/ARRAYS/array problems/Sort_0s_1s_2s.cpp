#include<iostream>
using namespace std;
void sort012(int arr[], int size);
void print(int arr[], int size);
int main()
{
    int arr[100];
    int size;
    cin>>size;
    for (int i = 0; i < size; i++)
    {
        /* code */
        cout<<"enter the element : ";
        cin>>arr[i];
    }
    sort012(arr,size);
    print(arr,size);
    return 0;
}
void print(int arr[], int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}


// * Approach 1
//  * counting 0 ,1, 2 and put all of them 
// *  It is not a good approach as it make it unusable with structure
void sort012(int arr[], int size)
{
    int count0=0,count1=0,count2 =0;
    for(int i =0;i<size;i++)
    {
        if(arr[i]== 0)
        {
            count0++;
        }
        if(arr[i]== 1)
        {
            count1++;
        }
        if(arr[i]== 2)
        {
            count2++;
        }
    }
    int i = 0;
    while(i<count0)
    {
        arr[i++] = 0;
    }
    while(i<(count0+count1))
    {
        arr[i++] = 1;
    }
    while(i<(count0+count1+count2))
    {
        arr[i++] = 2;
    }
} 
