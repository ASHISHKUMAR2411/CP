// non tail recursion is the recursion where it has recursion before the end that means that the after the ecursion it has activities to perform 

#include<iostream>
using namespace std;
int  fact(int n)
{
    if(n==0)
    {
        return 1;
    }
    else{
        return (n*fact(n-1));
        // !it is performing multiplication after the function returns that shows that it is non tail recursion 
    }
} 
int main()
{
    int factorial = fact(5);
    cout<<factorial<<endl;
    return 0;
}


