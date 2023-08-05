#include <iostream>
using namespace std;
void fun (int , int);
void fun (int);
void fun (char);
int main()
{
    int a , b ;
    char ch;
    cin >> a >> b;
    cin>>ch;
    ch=(char)a;
    fun(a);
    fun(a,b);
    fun(b);
    fun(ch);
    return 0;
}
void fun (int a, int b)
{ 
     cout << a << "\n" <<b<<endl;
}
void fun (int a)
{
    cout<< a <<"\n"<<endl;
}
void fun (char ch)
{
    cout<<(char)ch << "\n" << endl;
}