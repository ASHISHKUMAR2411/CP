#include <iostream>
using namespace std;
int main()
{
    //?  it is not allowed for the infinite value it show s access is denied .
    // int x =0, y=0;
    // int z = x/y;
    // cout<<z;
    // ? it is not allowed to use the undeclared variable ,
    // bool var ;
    // if(var)
    // {
    //     cout<<"true";
    // }
    // else cout<<"false";

    // ? we cam't access the value of the null pointer .
    // int *ptr = NULL;
    // cout<< ptr<<*ptr;

    // ? accessing the value out of the boundary
    // int A[5];
    // for (int i = 0 ; i <= 5;i++)
    // {
    //     cout<<A[i];
    // }

    // ? going beyond limit is also not allowed
    // int x = INT32_MAX;
    // cout<<x+1;

    // ? we can not modify the string as we want
    // string s = "ASHISH KUMAR";
    // s[0] = "A";
    // cout << s;

    // ? can't do like this 
    int i=8;
    int p = i++*i++;
    cout<<p;
    return 0;
}