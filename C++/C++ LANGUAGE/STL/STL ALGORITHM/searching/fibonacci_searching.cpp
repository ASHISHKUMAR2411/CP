// c++ program to find the fibonacci series of the 
#include<bits/stdc++.h>
using namespace std;
int fibonacciSearching(int arr[],int n, int ele)
{
    int fibo2 = 0;
    int fibo1 = 1;
    int fibo = fibo1+fibo2;
    while(fibo<n)
    {
        fibo2 = fibo1;
        fibo1 = fibo;
        fibo = fibo1+fibo2;
    }
    int offset = 1;
    while(fibo>1)
    {
        int i = min(offset+fibo2,n-1);
        if(a[i]<ele)
        {
            fibo = fibo1;
            fibo1 = fibo2;
            fibo2 = fibo - fibo1;
            offset = i;
        }
        else if (a[i]>ele)
        {
            /* code */
            fibo = fibo2;
            fibo1 = fibo1 - fibo2;
            fibo2 = fibo - fibo1;
        }
        else return i;
    }
    if(fibo1 && arr[offset+1]==ele) return offset+1;
    return -1;
}
int main()
{

}