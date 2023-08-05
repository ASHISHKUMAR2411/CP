//  Tail recursion means we are calling the function again at the end of the function where it does not have other operation tp perform afteer it and it can be simple for complier to compile as comapred to non tail recursion and it is very good to hae tail recursion than tail recursion than tail recursion

// * Example of tail recursion

#include<iostream>
using namespace std;
void print(int n)
{
    if(n<0)
    {
        return;
    }
    cout<<" "<<n;
    print(n-1);
}
int main()
{
    print(5);
    return 0;
}
