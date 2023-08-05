//? in this we are implementing jump search which is mixture of binary search and linear search in this what we do is that we jump a fix steps and once we found the element in between two jump we use linear search in that range .. time - O(sqrt(n))

// ! condition the array should be sorted ...

// * binary search is better than jump search but in worst case binary search we can use jump search at that condition .. 

//? the best case of jump search occur when the jump size is sqrt(n) where n is the size of the array ...

#include<bits/stdc++.h>
using namespace std;
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