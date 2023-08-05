#include<string>
#include<iostream>
using namespace std ;
void splitString(string str , string delimiter)
{
    int start = 0;
    int last = str.find(delimiter);
    while (last != -1)
    {
        /* code */
        cout<<str.substr(start,last-start)<<endl;
        start = last+delimiter.size();
        last = str.find(delimiter,start);
    }
    cout<<str.substr(start,last-start);
    

}
int main()
{
    string str;
    cout<<"\nEnter the string : ";
    getline(cin,str);
    splitString(str,"--");
    return 0;
}
