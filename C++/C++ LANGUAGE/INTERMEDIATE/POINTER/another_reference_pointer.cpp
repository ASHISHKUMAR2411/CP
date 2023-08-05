#include<iostream>
using namespace std;
int main()
{
   double x=9;
    double *ptr=&x;
    double *&b=ptr;
    cout<<" "<<x<<endl<<" "<<(int)ptr<<endl<<" "<<(float *)b<<endl;
    return 0;

}