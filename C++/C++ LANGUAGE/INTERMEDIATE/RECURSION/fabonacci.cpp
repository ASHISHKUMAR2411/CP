#include<iostream>
using namespace std;
void fabo(int n)
{
    static int i=0,a=1,b=1,sum=0;
    while(i<n)
    {
        sum=a+b; 
        cout<<" "<<sum;
        a=b;
        b=sum;
        i++;
        fabo(n-i);
    }

}
int main()
{
    int n;
    cout<<"\n enter the number of fabonacci series you want ";
    cin>>n;
    cout<<1<<" "<<1;
    fabo(n);
    return 0;
}