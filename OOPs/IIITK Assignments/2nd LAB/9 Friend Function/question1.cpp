// Write a C++ Program to shown the concept of friend function also define a specific problem where we can use this concept for solve the specific problem by writing a specific friend function in that class.
#include<bits/stdc++.h>
using namespace std;
class student
{
    private:
        int roll;
        string name;
        int age;
        string address;
        string course;
        string branch;
        string college;
        string university;
        string state;
        string country;
    public:
        void getdata()
        {
            cout<<"Enter the roll number of the student: ";
            cin>>roll;
            cout<<"Enter the name of the student: ";
            cin>>name;
            cout<<"Enter the age of the student: ";
            cin>>age;
            cout<<"Enter the address of the student: ";
            cin>>address;
            cout<<"Enter the course of the student: ";
            cin>>course;
            cout<<"Enter the branch of the student: ";
            cin>>branch;
            cout<<"Enter the college of the student: ";
            cin>>college;
            cout<<"Enter the university of the student: ";
            cin>>university;
            cout<<"Enter the state of the student: ";
            cin>>state;
            cout<<"Enter the country of the student: ";
            cin>>country;
        }
        void display()
        {
            cout<<"\nRoll number of the student: "<<roll;
            cout<<"\nName of the student: "<<name;
            cout<<"\nAge of the student: "<<age;
            cout<<"\nAddress of the student: "<<address;
            cout<<"\nCourse of the student: "<<course;
            cout<<"\nBranch of the student: "<<branch;
            cout<<"\nCollege of the student: "<<college;
            cout<<"\nUniversity of the student: "<<university;
            cout<<"\nState of the student: "<<state;
            cout<<"\nCountry of the student: "<<country;
        }
        friend void display_data(student);
};
void display_data(student s)
{
    cout<<"\nRoll number of the student: "<<s.roll;
    cout<<"\nName of the student: "<<s.name;
    cout<<"\nAge of the student: "<<s.age;
    cout<<"\nAddress of the student: "<<s.address;
    cout<<"\nCourse of the student: "<<s.course;
    cout<<"\nBranch of the student: "<<s.branch;
    cout<<"\nCollege of the student: "<<s.college;
    cout<<"\nUniversity of the student: "<<s.university;
    cout<<"\nState of the student: "<<s.state;
    cout<<"\nCountry of the student: "<<s.country;
}
int main()
{
    student s;
    s.getdata();
    s.display();
    display_data(s);
    return 0;
}
// Output:
// Enter the roll number of the student: 1
// Enter the name of the student: Ashish
// Enter the age of the student: 19
// Enter the address of the student: Uttar Pradesh
// Enter the course of the student: B.Tech
// Enter the branch of the student: CSE
// Enter the college of the student: IIIT Kota
// Enter the university of the student: IIIT Kota
// Enter the state of the student: Rajasthan
// Enter the country of the student: India
//