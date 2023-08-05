#include<iostream>
using namespace std;
int getSum(int n)
{
    int sum = 0;
    while (n != 0)
    {
        sum = sum + n % 10;
        n = n / 10;
    }
    return sum;
}
int main(){
    int num ;
    cout<<"enter the number : ";
    cin>>num;
    cout<<"Sum of digits : "<<getSum(num)<< endl;
    return 0;
}