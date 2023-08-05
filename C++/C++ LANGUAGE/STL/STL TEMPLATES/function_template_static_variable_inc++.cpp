//* in c++ we have to take care about that we have different installation of template for different data type so in order to show that we are going to show the same . 
#include<iostream>
using namespace std;
template <typename T>
void fun(const T& x)
{
    static int i=10;
    cout<<++i<<endl;
}
int main()
{
    fun(1);
    cout<<"\n";
    fun(12);
    cout<<"\n";
    fun(31);
    cout<<"\n";
    fun(2.3);
    cout<<"\n";
    return 0;
}