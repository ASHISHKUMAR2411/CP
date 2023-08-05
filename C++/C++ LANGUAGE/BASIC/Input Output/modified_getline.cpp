#include<iostream>
#include<cstring>
// reason behind this is that getline only reads till enter it doea not mater if there is only enter 
int main()
{
    std::string str;
    int t =4;
    while(t--)
    {
        getline(std::cin,str);
        while(str.length()==0)
        {
            getline(std::cin,str);
        }
        std::cout<<str<<" Newline \n";
    }
    return 0;
}