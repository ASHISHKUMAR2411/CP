// CPP program to find the size of the array inside the function 
#include<iostream>
#include<string>
using namespace std;
void findSize(int arr[])
{
    cout<<sizeof(arr)<<endl;
}
int main()
{
    int arr[10];
    cout<<sizeof(arr)<<endl;
    findSize(arr);
    return 0;
}