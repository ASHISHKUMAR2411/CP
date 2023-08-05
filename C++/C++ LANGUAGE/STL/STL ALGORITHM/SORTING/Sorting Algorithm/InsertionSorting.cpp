#include<iostream>
using namespace std;
// insertion sorting is used for the sorting in usoretd part and sorted part, in which we compare the unsorted part with the sorted part and we swap the bigger element one ahed and the smaller element infront of them .

// BEST case :- O(n)
// Worst Case :- O(n^2)
// Case:- O(n*i)
//stable
//online
//in place sorting


template<class T>
void insertionSort(T arr[], int size)
{
    T temp;
    int j =0;
    for (int  i = 1; i < size; i++)
    {
        /* code */
        j=i;
        temp = arr[i];
        while(j > 0 && arr[j-1] > temp)
        {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = temp;
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
    // insertionSort<int>(arr,size);
    // insertionSort<char>(arr,size);
    insertionSort<string>(arr,size);
    // print<int>(arr,size);
    print<string>(arr,size);
    // print<char>(arr,size);
}