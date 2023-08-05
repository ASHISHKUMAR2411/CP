// There is no chaining of comparison operators in C
// In Python,
// expression like “c > b > a” is treated as “c > b and b > a”, but this type of chaining doesn’t happen in C.For example consider the following program.The output of following program is “FALSE”.
#include<iostream>
using namespace std;

//  this is wrong 

int main()
{
    int a = 10 , b = 30 , c = 40;
    if(a>b>c)
    {
        cout>>"correct is : ";
    }
    else{
        cout<<"not correct : ";
    }
    return 0;
}