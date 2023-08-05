// * In this we are just removing recursion with goto statements and it's make it friendly
#include<iostream>
using namespace std;
void print(int n)
{
    start:
    if(n<0)
    {
        return;
    }
    cout<< " " <<n;
    n = n-1;
    goto start;
}
int main()
{
    print(5);
    return 0;
}