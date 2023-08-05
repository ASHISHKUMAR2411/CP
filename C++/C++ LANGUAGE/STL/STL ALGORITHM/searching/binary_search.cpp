//? C++ program to just show the way we can implement the binarySearch in three methods c++ program to implement the binary search and in this it takes O(log n) time 

#include <bits/stdc++.h>
using namespace std;


// first method to find the binary search ...
int binarySearch(vector<int> arr, int ele)
{
    sort(arr.begin(), arr.end());
    int mid = 0, low = 0, high = (int)(arr.size() - 1);
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] == ele)
            return mid;
        else if (arr[mid] > ele)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}


// second method to find the binary method ...
// using recursion 
int binarySearchRecursive(vector<int> S, int low, int high, int ele)
{
    if (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (s[mid] == ele)
            return mid;
        else if (s[mid] > ele)
            return binarySearchRecursive(S, l, mid - 1, ele);
        else
            return binarySearchRecursive(S, mid + 1, high, ele);
    }
    return -1;
}



// now we are using binary search using its best implementation ..
const int N = 1e6 + 4;
int a[N];
int n; // array size 
int k;// element to search 
bool check(int dig)
{
    int ele = a[dig];
    if(k<=ele)
        return 1;
    else 
        return 0;
} 
void binarySearchCheckFunction(int low , int high)
{
    while(low<high)
    {
        int mid = (low+high)/2;
        if(check(mid)){
            high = mid;
        }
        else
            low = mid +1 ;
    }
    if(a[low]==k)
    {
        cout<<"element found at : "<<low;
    }
    else 
    {
        cout<<"element not found : ";
    }
}


int main()
{
    // give the array and the element to find the array 
}