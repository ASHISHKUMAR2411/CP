#include <bits/stdc++.h>
using namespace std;
int main()
{
    // long double p;
    // scanf("%.15lf",&p);
    // printf("%1.15lf\n",p);
    // // we can use set precision 
    // printf("%1.25lf", (double)22 / (double)7);
    long long int a = 0 , b = 1 , sum = 0,count=0;
    while(sum<10000000009) 
    {
        sum = a+b;
        a = b;
        b = sum;
        count++;
    }
    cout<<count<<endl;
    cout<<sum<<endl;
}