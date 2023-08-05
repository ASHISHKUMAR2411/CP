#include<bits/stdc++.h>
using namespace std;
int main()
{
    // wild pointer are the pointer in which we have the pointer not initilaise because of which it behaves randomly and it is considered as bad pratice
    // we should always initialise the pointer , if not knowing then NULL
    // in this the program runs but it does not have any value to show as it is wild pointer so it shows 
    // segmentation fault
    // int *p;
    // *p=12;
    // cout<<" "<<*p<<endl;
    // return 0;
    // now changing the above code 
    // in debugging the declaration part is skipped as well 

    // in this code also segmentation fault as it is initialised to a pointer which is not showing any address
    // int *p=NULL;
    // *p=12;
    // cout<<" "<<*p<<endl;
    // return 0;

    // now again changing the code 
    // int *p=12;
    // *p=12; we cannot initialise like that 
    // so tis is good to do
    int a=5;
    int *p=&a;
    cout<<" "<<*p<<endl;
    return 0;
}