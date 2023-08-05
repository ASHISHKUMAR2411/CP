// C++ program to show the demonstration of what class look like 
#include<bits/stdc++.h>
using namespace std;
class introduction
{
private:
    /* data */
    // here we have access specifier in class i.e means only public member and member function can be accessed by object of the class from outside , 
public:
    string str1;
    void print()
    {
        cout<<" The name is : "<<str1;
    }
    // constructor 
    introduction(/* args */);
    // destructor 
    ~introduction();
};
// constructor function 
introduction::introduction(/* args */)
{
}
// destructor function 
introduction::~introduction()
{
}

int main()
{
    introduction object;
    cout<<"\nenter the name of the object : ";
    getline(cin,object.str1);
    object.print();
    return 0;
}