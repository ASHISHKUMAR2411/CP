#include<bits/stdc++.h>
using namespace std;

// ? SEARCHING

//! LINEAR SEARCH O(n)
int linearSearch(vector<int> s , int n)
{
    for(int i =0;i<(int)(s.size());i++)
    {
        if(s[i]==n)
        {
            return i;
        }
    }
    return -1;
}

// ! BINARY SEARCH  O(log(n))
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

//! JUMP SEARCH O(sqrt(n))
int jumpSearch(int a[],int n ,int ele)
{
    // we can include some staring condition but never the less it will be covered by the last line of the function ..
    // if(a[0]>ele)
    //     return -1;
    // if(a[n-1]<ele)
    //     return -1;
    int step = sqrt(n);
    int prev = 0;
    // finding the range where the element lies 
    while(a[min(step,n)-1]<ele) // while(a[step]<ele && step<=n-1)
    {
        prev = step;
        step += sqrt(n);
        if(prev>=n)
            return -1;
    }
    // linear search of the element 
    while(a[prev]<x)
    {
        prev++ ;
        // if element not found in that range .. 
        if(prev == min(step,n))
            return -1;
    }
    if(a[prev]==x)
        return prev;
    // if element not found in that range or element was in between the range but given in the array or the element was smaller than smallest element ..
    return -1;
}

// ! INTERPOLATION SEARCH O(log(log(n)))
int interpolationSearch(int a[],int low, int high , int ele)
{
    int pos ;
    while(low<=high && ele >= a[low] && ele<=a[high])
    {
        pos = low + (ele-a[low])*(((double)(high-low))/(a[high]-a[low]));
        if(a[pos]==ele)
            return pos;
        if(a[pos]<ele)
            return interpolationSearch(a,pos+1,high,ele);
        if(a[pos]>ele)
            return interpolationSearch(a,low,pos-1,ele);
    }
    return -1;
}

// ! EXPONENTIAL SEARCH O(Log(n)) used for unbounded search i.e when size of array is not known or infinite .. better than binary search 
int exponentialSearch(int a[],int n , int ele)
{
    if(a[0]==ele)
        return 0;
    int i = 1;
    while(i<n && a[i]<=ele)
        i = i*2;
    return binarySearch(a,i/2,min(i,n-1),ele);
}

//? SORTING 