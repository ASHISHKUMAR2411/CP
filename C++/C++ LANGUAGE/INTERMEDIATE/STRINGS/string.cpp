#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str1("first string ");
    string str2(str1);
    string str3(5,'#');
    string str4(str1,6,6);
    string str5(str2.begin(),str2.begin()+5);
    cout<<str1<<endl;
    cout<<str2<<endl;
    cout<<str3<<endl;
    cout<<str4<<endl;
    cout<<str5<<endl;
    string str6=str4;
    cout<<str6<<endl;
    str4.clear();
    int len=str6.length();
    cout<<"\n the length is "<<len<<endl;
    char ch=str6.at(2);
    cout<<"\n the third character is : "<<ch<<endl;
    char ch_f=str6.front();
    char ch_b=str6.back();
    cout<<"the first character : "<<ch_f<<" the second character : "<<ch_b<<endl;
    const char *charstr = str6.c_str();
    printf("%s\n",charstr);
    str6.append(" extension").append(" is");
    str4.append(str6,0,4);
    cout<<str6<<endl;
    cout<<str4<<endl;
    if(str6.find(str4) != string::npos)
    {
        cout<<"\n the string 4 is found at "<<str6.find(str4)<<" pos"<<endl;
    }
    else
    {
        cout<<"\n str4 is  not found at str6"<<endl;
    }
    cout<<str6.substr(7,3)<<endl;
    cout<<str6.substr(3);
    str6.erase(7,4);
    cout<<str6<<endl;
    str6.erase(str6.begin()+5,str6.end()-3);
    cout<<str6<<endl;
    str6="this is an example of string  ";
    cout<<str6<<endl;
    str6.replace(2,7," ashish kumar");
    cout<<str6<<endl;
    return 0;
}