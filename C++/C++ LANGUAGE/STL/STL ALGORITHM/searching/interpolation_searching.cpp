// ? c++ program to do interpolation search in array (sorted) where the element are uniformly distributed and the main thing is that it is improved search in binary , the basic idea behind the search is that it is like binary search but instead of checking the middle value it check the element closer to the searching element .
// ! time complexity is O(log(log(n))) in average case and O(n) in worst case   
#include<bits/stdc++.h>
using namespace std;
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