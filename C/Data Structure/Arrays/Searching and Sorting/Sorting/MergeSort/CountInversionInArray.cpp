// program to count the inversion in an array
#include<bits/stdc++.h>
using namespace std;
// O(n*n) time complexity
int countInversion(int arr[], int n){
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i] > arr[j]){
                count++;
            }
        }
    }
    return count;
}
// better solution with O(nlogn) time complexity and O(n) space complexity
int merge(int arr[], int low, int mid, int high)
{
    int size1 = mid - low + 1;
    int size2 = high - mid;
    int left[size1], right[size2];
    // here we are storing the element into them
    for (int i = 0; i < size1; i++)
    {
        left[i] = arr[low + i];
    }
    for (int j = 0; j < size2; j++)
    {
        right[j] = arr[mid + 1 + j];
    }

    // then we are comparing each and every element before merging them into another array arr[] ,
    int i = 0, j = 0, k = low, res = 0;
    while (i < size1 && j < size2)
    {
        if (left[i] < right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
            res += size1 - i;
        }
        k++;
    }
    //  then we are checking the leftout element in any of the two array and then simply copying them into the main array as they  are already sorted .
    while (i < size1)
    {
        arr[k++] = left[i++];
    }
    while (j < size2)
    {
        arr[k++] = right[j++];
    }
    return res;
}
// Recursion function to sort the array
int countInversion2(int arr[], int l,int r){
    int count = 0;
    if(r>l){
        int mid = (l+r)/2;
        count += countInversion2(arr, l, mid);
        count += countInversion2(arr, mid+1, r);
        count += merge(arr, l, mid, r);
    }
    return count;
}

int main(){
    int arr[] = {1, 20, 6, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<countInversion(arr, n)<<endl;
    cout<<countInversion2(arr, 0, n-1)<<endl;
    return 0;
}