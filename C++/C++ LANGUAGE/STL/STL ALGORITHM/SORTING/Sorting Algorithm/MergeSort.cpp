// * It is also divide and conquer algorithm 
// * It divides the array into two half and sort them and then merge them accordingly 
#include<iostream>
using namespace std;
template<class T>
void merging(T arr[], int low,int mid,int high)
{
    int size1 = mid - low +1 ;
    int size2 = high - mid;
    int left[size1] , right[size2];
    for(int i =0 ;i<size1;i++)
    {
        left[i] = arr[low+i]; 
    }
    for(int j = 0 ;j<size2;j++)
    {
        right[j] = arr[mid + 1 + j];
    }
    int i =0 ,j =0 , k = low;
    while(i<size1 && j< size2)
    {
        if(left[i]<right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while(i<size1)
    {
        arr[k++] = left[i++];
    }
    while(j<size2)
    {
        arr[k++] = right[j++];
    }
}
template<class T>
void mergeSort(T arr[], int low , int high )
{
     if(low>=high){
        return;//returns recursively
    }
    int mid =  low + (high-low)/2;
    mergeSort<int>(arr,low,mid);
    mergeSort<int>(arr,mid+1,high);
    merging<int>(arr,low,mid,high);
}

template<class T>
void print(T arr[], int size )
{
    for(int i =0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int arr[100],size;
    cin>>size;
    for(int i=0;i<size;i++)
    {
        cout<<"Enter the element : ";
        cin>>arr[i];
    }
    mergeSort<int>(arr,0,size-1);
    print<int>(arr,size);
    return 0;
}

// * T(n) = 2T(n/2) + θ(n)
// *The above recurrence can be solved either using the Recurrence Tree method or the Master method. It falls in case II of Master Method and the solution of the recurrence is θ(nLogn). Time complexity of Merge Sort is  θ(nLogn) in all 3 cases (worst, average and best) as merge sort always divides the array into two halves and takes linear time to merge two halves.
// *Auxiliary Space: O(n)
// *Algorithmic Paradigm: Divide and Conquer
// *Sorting In Place: No in a typical implementation
// *Stable: Yes

// *Drawbacks of Merge Sort

//Slower comparative to the other sort algorithms for smaller tasks.
// Merge sort algorithm requires an additional memory space of 0(n) for the temporary array.
// It goes through the whole process even if the array is sorted.
