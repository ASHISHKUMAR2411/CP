#include<iostream>
int main()
{
    int input;
    std::cout<<"\nenter any character to stop the process";
    int count =0;
    std::cout<<"\nnow enter the inputs \n";
    while(std::cin>>input)
    {
        // it also fails when the limits exceeds out of control for storing inside int .
        count++;
    }
    std::cout<<" count : "<<count;
    return 0;
}