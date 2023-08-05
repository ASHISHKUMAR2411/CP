#include<iostream>
using namespace std;
// in three way , it is a stable and in place sortung algoritm , where we have a section of the sorting as smaller than the pivot element , then one section is equal to the pivot element or equal element section and third where we have the greater section.

template<class T>
void swapping(T &value1 , T &value2)
{
    T temp ;
    temp = value1;
    value1 = value2 ;
    value2 = temp;
}


template<class T >
void partition(T arr[] ,int left , int right, int &i,int &j)
{
    i = left-1,j=right;
    int p = left-1, q = right;
    int v = arr[right];
    while(true)
    {
        while(arr[++i]<v);
        while(arr[--j]>v)
        {
            if(j==left)
            {
                break;
            }
        }
        if(i>=j)
        {
            break;
        }
        swapping(arr[i],arr[j]);
        if(arr[i] == v)
        {
            p++;
            swapping(arr[p],arr[i]);
        }
        if(arr[j] == v)
        {
            q--;
            swapping(arr[j],arr[q]);
        }
    }
    swapping(arr[i],arr[right]);
    j=i-1;
    for(int k = left;k<p;k++,j--)
    {
        swapping(arr[k],arr[j]);
    }
    i = i+1;
    for(int k = right-1 ; k>q ;k--, i++)
    {
        swapping(arr[i],arr[k]);
    }

}

template<class T>
void quickSort(T arr[], int left , int right){
    if(right<=left)
    {
        return;
    }
    int i,j;
    partition(arr,left,right,i,j);
    quickSort(arr,left,j);
    quickSort(arr,i,right);
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
    int arr[100];
    // char arr[100];
    // string arr[100];
    int size;
    cin>>size;
    for (int  i = 0; i < size; i++)
    {
        cout<<"\nenter the element : ";
        cin>>arr[i];
        /* code */
    }
    cout<<"Sorted Array :  \n";
    quickSort<int>(arr,0,size-1);
    // bubbleSort<char>(arr,size);
    // quickSort<string>(arr,0,size-1);
    print<int>(arr,size);
    // print<string>(arr,size);
    // print<char>(arr,size);
}
