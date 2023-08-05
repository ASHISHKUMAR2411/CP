// as quick sort is not inplace but part of it is inplace that is partiton function is in place  we can do one thing which is that we can apply recursion to a smaller part this will help in optimisation and sped.

// * It will require only O(log(n)) extra space at worst case which is best efficieny for quick sort 

// * Tail call elimination in quick sort make its more better and makes it's complier friendly and it because of that it is also bettter than merge sort 

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
int Partition(T arr[],int low ,int high)
{
    T pivot = arr[high];
    int i = low -1;
    for (int j = low; j <= high-1; j++)
    {
        /* code */
        if(arr[j]<pivot)
        {
            i++;
            swapping(arr[i],arr[j]);
        }
    }
    swapping(arr[i+1],arr[high]);
    return i+1 ;
}

template<class T>
void quickSort(T arr[], int low , int high)
{
    while(low<high)
    {
        int pi = Partition<T>(arr,low,high);
        if((pi - low) <( high - pi))
        {
            quickSort(arr,low,(pi-1));
            low = pi+1;
        }
        else
        {
            quickSort(arr,(pi+1),high);
            high = pi -1 ;
        }
    }

//? start:
//?     if(low<high)
//?     {
// ?        int pi = Partition<T>(arr,low,high);
//  ?       quickSort(arr,low,pi-1);
//   ?      low = pi+1;
//    ?     high = high;
//     ?    goto start;
//     ? }

    //* we can also use while loop for the same 
    //* while(low<high)
    //* {
    //*     int pi = Partition<T>(arr,low,high);
    //*     quickSort(arr,low,pi-1);
    //*     low = pi+1;
    //* }
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
    quickSort<string>(arr,0,size);
    // print<int>(arr,size);
    print<string>(arr,size);
    // print<char>(arr,size);
}
