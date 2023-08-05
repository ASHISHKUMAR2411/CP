#include<bits/stdc++.h>
using namespace std;
template<class T>
void swapping(T &value1 , T &value2)
{
    T temp ;
    temp = value1;
    value1 = value2 ;
    value2 = temp;
}
template<class T>
void bubbleSort(T arr[],int size)
{
    // Base case
    if (size == 1)
        return;

// One pass of bubble sort. After
    // this pass, the largest element
    // is moved (or bubbled) to end.
    for (int  j = 0; j  < size-i-1; j++)
    {
        if(arr[j]>arr[j+1])
        {
            swapping(arr[j],arr[j+1]);
        }
    }
    // Largest element is fixed,
    // recur for remaining array
    bubbleSort(arr,size-1);
}

template<class T>
void print(T arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    // int arr[100];
    // char arr[100];
    string arr[100];
    int size;
    cin>>size;
    for (int  i = 0; i < size; i++)
    {
        cout<<"\nenter the element : ";
        cin>>arr[i];
        /* code */
    }
    cout<<"Sorted Array :  \n";
    // bubbleSort<int>(arr,size);
    // bubbleSort<char>(arr,size);
    bubbleSort<string>(arr,size);
    // print<int>(arr,size);
    print<string>(arr,size);
    // print<char>(arr,size);
}