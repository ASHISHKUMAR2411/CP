#include<bits/stdc++.h>
using namespace std;
int LongestSubsequenceEvenOdd(int arr[],int n)
{
    int res = 0 , count = 0 , flag = arr[0]%2;
    for(int i=0;i<n;i++)
    {
        if(arr[i]%2 == flag)
        {
            flag = !flag;
            count++;
        }
        else
        {
            count = 1;
        }
        res = max(res,count);
    }
    return res;
}
int main(){
    int arr[] = {8,12,10,11,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<LongestSubsequenceEvenOdd(arr,n);
    return 0;
}