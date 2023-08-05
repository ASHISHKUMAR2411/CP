#include<iostream>
#include<string>
using namespace std;
void swap(string &ch1,string &ch2)
{
    string temp=ch1;
    ch1=ch2;
    ch2=temp;
}
int main()
{
    string ch1="Ashish ";
    string ch2="Kumar";
    swap(ch2,ch1);
    cout<<" string 1 is : "<<ch1<<endl<<" string 2 is : "<<ch2<<endl;
    return 0;
}