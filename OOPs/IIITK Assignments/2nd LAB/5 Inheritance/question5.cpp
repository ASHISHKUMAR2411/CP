// design a student class representing student roll. No. and test class derive from the student class representing score of the various subjects and sports class representing the score in the sports. The sports and test class should be inherited by a result class having the functionalities to add the score and display the final result for a student.
#include <bits/stdc++.h>
using namespace std;
class student
{
    int roll;

public:
    void getdata()
    {
        cout << "Enter the roll number: ";
        cin >> roll;
    }
    void display()
    {
        cout << "Roll number: " << roll << endl;
    }
};

class test : public student
{
    int m1, m2, m3, m4, m5;

public:
    void getdata()
    {
        student::getdata();
        cout << "Enter the marks in 5 subjects: ";
        cin >> m1 >> m2 >> m3 >> m4 >> m5;
    }
    void display()
    {
        student::display();
        cout << endl << "For Subjects : " << endl;
        cout << "Marks in 5 subjects: " << m1 << " " << m2 << " " << m3 << " " << m4 << " " << m5 << endl;
    }
};

class sports
{
    int m1;

public:
    void getdata()
    {
        cout << "Enter the marks in sports: ";
        cin >> m1;
    }
    void display()
    {
        cout << endl << "For Sports" << endl;
        cout << "Marks in sports: " << m1 << " " << endl;
    }
};

class results : public test, public sports
{
public:
    void getdata()
    {
        test::getdata();
        sports::getdata();
    }
    void display()
    {
        test::display();
        sports::display();
    }
};

int main()
{
    results r;
    cout << "Give the data to find the result of student " << endl;
    r.getdata();
    cout << endl;
    cout << "The final result is : " << endl;
    r.display();
    return 0;
}

// Output:
// Give the data to find the result of student 
// Enter the roll number: 1
// Enter the marks in 5 subjects: 90 90 90 90 90
// Enter the marks in sports: 90
// Enter the marks in 5 subjects: 90 90 90 90 90
// Enter the marks in sports: 90
// The final result is
// Roll number: 1
// For Subjects :
// Marks in 5 subjects: 90 90 90 90 90
// For Sports
// Marks in sports: 90
