#include<iostream>
using namespace std;
void swap(char *&ch1,char *&ch2)
{
    char *temp=ch1;
    ch1=ch2;
    ch2=temp;
    return;
}
int main()
{
    char *ch1="AShish ";
    char *ch2="Kumar ";
    swap(ch1,ch2);
    cout<<" ch1 = "<<ch1<<endl<<"ch2 = "<<ch2<<endl;
    return 0;
}