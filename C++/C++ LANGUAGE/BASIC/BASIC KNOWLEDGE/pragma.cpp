#include<iostream>
using namespace std;
void fun1();
void fun2();
#pragma startup fun1
#pragma exit fun2
// pragma is used to give special instruction to the complier 
// pragma startup is used to give the instruction to the complier that it has to start up at these function and 
// pragma end gives the instructio the complier that the it should it ends st that function 
// pragma also is used to give the instruction to the complier that to hides the warning.

void fun1()
{
    cout<<"\n Inside Function1 ";
}
void fun2()
{
    cout<<"\n Inside Function 2";
}
int main()
{
    void fun1();
    void fun2();
    cout<< "\nInside Main";
    return 0;
}