#include<iostream>
#include<new>
int main()
{
    try
    {
        int *a =new int[100000000000000];
        std::cout<<"hello Ashish";
    }
    catch(std::bad_alloc & ba)
    {
        std::cerr << "bad alloc caught"<<ba.what() << '\n';
    }
    
}