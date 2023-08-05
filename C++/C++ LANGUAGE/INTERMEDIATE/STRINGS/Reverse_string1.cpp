// CPP program to find the reverse of the string PART 1
#include<iostream>
#include<string>
#include<array>
using namespace std;
void REVERSE(string str)
{
    // COMPLETED 
    char temp ;
    for(int i =0;i<(str.length()/2);i++)
    {
        temp = str[i];
        str[i] = str[str.length()-1-i];
        str[str.length()-1-i] = temp;
    }
    cout<<"\n "<<str;
}
int main()
{
    // WRITING MY own reverse function 
    string str1 = "ASHISH KUMAR";
    REVERSE(str1);
    return 0;
}