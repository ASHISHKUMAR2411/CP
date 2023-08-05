#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void printx2(int a)
{
    cout<<a*2<<" ";
}
struct Class2
{
    void operator()(int a)
    {
        cout<<a*3<<" ";
    }
}ob1;
int main()
{
    int a[5]={1,2,3,4,5};
    cout<<"Using Array :"<<endl;
    cout<<"Multiple of 2 of element are ";
    for_each(a,a+5,printx2);
    cout<<endl;
    cout<<"Multiple of 3 of element are : ";
    for_each(a,a+5,ob1);
    cout<<endl;
    vector<int> arr1={4,5,8,3,1};
    cout<<"Using Vectors : "<<endl;
    cout<<"Multiple of 3 of element are :";
    for_each(arr1.begin(),arr1.end(),ob1);
    cout<<endl;
    return 0;
}