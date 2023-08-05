// Write a C++ Program to implement a friend function through a method of another class as well as implement the friend function using the global function.
#include<bits/stdc++.h>
using namespace std;
class student
{
    int roll;
    string name;
    public:
        void getdata()
        {
            cout<<"Enter roll number: ";
            cin>>roll;
            cout<<"Enter name: ";
            cin>>name;
        }
        friend void display(student s);
};
void display(student s)
{
    cout<<"Roll number: "<<s.roll<<endl;
    cout<<"Name: "<<s.name<<endl;
}
int main()
{
    student s;
    s.getdata();
    display(s);
    return 0;
}
// Output:
// Enter roll number: 1
// Enter name: Rohan
// Roll number: 1
// Name: Rohan
// Process returned 0 (0x0)   execution time : 0.000 s
