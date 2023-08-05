// UsingUnaryOperationUsingTransform
// here we are using the unary operation using transform function in c++ where we are actually implementing one idea which is that we want to pass more than one argument into function which allows only one argument to pass .
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr1[] = {1,2,3,4,5};
    int arr2[] = {0,9,8,7,6};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    int result[10];
    transform(arr1,arr1+n,arr2,result,plus<int>());
    for(int i =0;i<n;i++)
    {
        cout<<" "<<result[i]<<" ";
    }
    return 0;
}