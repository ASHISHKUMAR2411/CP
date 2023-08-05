// Write a C++ Program to a base class student which contains the attributes like student roll number, name etc.and the operation included the information from the roll number, display the student information and assigned the value to the various attribute of the class.Now, this base class derived to new classes namely test and sports.The derived classes also contain some distinct attributes related to the uniqueness of that class.Once again create a child class result by inheriting the features of test and sports class.Now, Write the definition of the child class result by removing the duplication of the inherited member due to the multiple paths from student class to results class.
#include<bits/stdc++.h>
using namespace std;
class student
{
    protected:
        int roll;
        string name;
        string branch;
        int year;
    public:
        void getdata()
        {
            cout<<"Enter the roll number: ";
            cin>>roll;
            cout<<"Enter the name: ";
            cin>>name;
            cout<<"Enter the branch: ";
            cin>>branch;
            cout<<"Enter the year: ";
            cin>>year;
        }
        void display()
        {
            cout<<"Roll number: "<<roll<<endl;
            cout<<"Name: "<<name<<endl;
            cout<<"Branch: "<<branch<<endl;
            cout<<"Year: "<<year<<endl;
        }
};
class test:public student
{
    protected:
        int m1,m2,m3;
    public:
        void getdata()
        {
            student::getdata();
            cout<<"Enter the marks of three subjects: ";
            cin>>m1>>m2>>m3;
        }
        void display()
        {
            student::display();
            cout<<"Marks of three subjects: "<<m1<<" "<<m2<<" "<<m3<<endl;
        }
};
class sports:public student
{
    protected:
        int m1,m2,m3;
    public:
        void getdata()
        {
            student::getdata();
            cout<<"Enter the marks of three subjects: ";
            cin>>m1>>m2>>m3;
        }
        void display()
        {
            student::display();
            cout<<"Marks of three subjects: "<<m1<<" "<<m2<<" "<<m3<<endl;
        }
};
class result:public test,public sports
{
    public:
        void display()
        {
            test::display();
            sports::display();
        }
};
int main()
{
    result r;
    r.getdata();
    r.display();
    return 0;
}
// Output:
// Enter the roll number: 1
// Enter the name: Rishabh
// Enter the branch: CSE
// Enter the year: 1
// Enter the marks of three subjects: 90 80 70
// Enter the marks of three subjects: 80 90 70
// Roll number: 1
// Name: Rishabh
// Branch: CSE
// Year: 1
// Marks of three subjects: 90 80 70
// Marks of three subjects: 80 90 70
//