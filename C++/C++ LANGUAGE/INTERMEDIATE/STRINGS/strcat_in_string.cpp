// CPP program to find the usage of strcat() function in cpp
#include<bits/stdc++.h>
using namespace std;
int main()
{
    char* str = "ASHISH ";
    char* str2 = "KUMAR";
    char *str3 = strcat(&str[0],&str2[0]);
    // this shows that the character string is not changed 
    cout<<str<<endl;
    cout<<str2<<endl;
    cout<<str3<<endl;
    //  strcat(str3,&str[0]);
    cout<<str<<endl;
    cout<<str2<<endl;
    cout<<str3<<endl;
}