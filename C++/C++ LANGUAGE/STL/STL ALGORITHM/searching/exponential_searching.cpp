// C++ program to show the implementation of the exponential searching which search in O(log(n)) time. 
// in exponential search what we do is first find the range of element where the element can be found and then apply binary search to it 
#include<bits/stdc++.h>
using namespace std;
int exponentialSearch(int a[],int n , int ele)
{
    if(a[0]==ele)
        return 0;
    int i = 1;
    while(i<n && a[i]<=ele)
        i = i*2;
    return binarySearch(a,i/2,min(i,n-1),ele);
}
