// Write a C++ Program to Derive a class called employee2 from the employee class.This new class should add a type double data item called compensation and, also an enum type called period to indicate whether the employee is paid hourly,weekly, or monthly.For simplicity you can change the manager, scientist and labourer classes so they are derived from employee2 instead of employee.However, note that in many circumstances it might be more in the spirit of OOP to create a separate base class called compensation and three new class manager2, scientist2 and labour2 and use multiple inheritances to derive these classes from the original manager, scientist and labourer classes and from compensation.This way none of the original classes needs to be modified.
#include<bits/stdc++.h>
using namespace std;

class employee
{
    protected:
        string name;
        int id;
        float salary;
    public:
        void getdata()
        {
            cout<<"Enter the name: ";
            cin>>name;
            cout<<"Enter the id: ";
            cin>>id;
            cout<<"Enter the salary: ";
            cin>>salary;
        }
        void display()
        {
            cout<<"Name: "<<name<<endl;
            cout<<"Id: "<<id<<endl;
            cout<<"Salary: "<<salary<<endl;
        }
};
class employee2:public employee
{
    protected:
        double compensation;
        enum period
        {
            hourly,
            weekly,
            monthly
        }p;
    public:
        void getdata()
        {
            employee::getdata();
            cout<<"Enter the compensation: ";
            cin>>compensation;
            cout<<"Enter the period: ";
            cin>>p;
        }
        void display()
        {
            employee::display();
            cout<<"Compensation: "<<compensation<<endl;
            cout<<"Period: "<<p<<endl;
        }
};
class manager: public employee2
{
    public:
        void getdata()
        {
            employee2::getdata();
            cout<<"Enter the compensation: ";
            cin>>compensation;
            cout<<"Enter the period: ";
            cin>>p;
        }
        void display()
        {
            employee2::display();
            cout<<"Compensation: "<<compensation<<endl;
            cout<<"Period: "<<p<<endl;
        }
};
class scientist: public employee2
{
    public:
        void getdata()
        {
            employee2::getdata();
            cout<<"Enter the compensation: ";
            cin>>compensation;
            cout<<"Enter the period: ";
            cin>>p;
        }
        void display()
        {
            employee2::display();
            cout<<"Compensation: "<<compensation<<endl;
            cout<<"Period: "<<p<<endl;
        }
};
class labour: public employee2
{
    public:
        void getdata()
        {
            employee2::getdata();
            cout<<"Enter the compensation: ";
            cin>>compensation;
            cout<<"Enter the period: ";
            cin>>p;
        }
        void display()
        {
            employee2::display();
            cout<<"Compensation: "<<compensation<<endl;
            cout<<"Period: "<<p<<endl;
        }
};
class compensation : public employee2
{
    public:
        void getdata()
        {
            employee2::getdata();
            cout<<"Enter the compensation: ";
            cin>>compensation;
            cout<<"Enter the period: ";
            cin>>p;
        }
        void display()
        {
            employee2::display();
            cout<<"Compensation: "<<compensation<<endl;
            cout<<"Period: "<<p<<endl;
        }
};
class manager2: public compensation
{
    public:
        void getdata()
        {
            compensation::getdata();
            cout<<"Enter the compensation: ";
            cin>>compensation;
            cout<<"Enter the period: ";
            cin>>p;
        }
        void display()
        {
            compensation::display();
            cout<<"Compensation: "<<compensation<<endl;
            cout<<"Period: "<<p<<endl;
        }
};
class scienctist2: public compensation
{
    public:
        void getdata()
        {
            compensation::getdata();
            cout<<"Enter the compensation: ";
            cin>>compensation;
            cout<<"Enter the period: ";
            cin>>p;
        }
        void display()
        {
            compensation::display();
            cout<<"Compensation: "<<compensation<<endl;
            cout<<"Period: "<<p<<endl;
        }
};
class labour2: public compensation
{
    public:
        void getdata()
        {
            compensation::getdata();
            cout<<"Enter the compensation: ";
            cin>>compensation;
            cout<<"Enter the period: ";
            cin>>p;
        }
        void display()
        {
            compensation::display();
            cout<<"Compensation: "<<compensation<<endl;
            cout<<"Period: "<<p<<endl;
        }
};
int main()
{
    manager m;
    m.getdata();
    m.display();
    scientist s;
    s.getdata();
    s.display();
    labour l;
    l.getdata();
    l.display();
    compensation c;
    c.getdata();
    c.display();
    manager2 m2;
    m2.getdata();
    m2.display();
    scienctist2 s2;
    s2.getdata();
    s2.display();
    labour2 l2;
    l2.getdata();
    l2.display();
    return 0;
}
// Output:
// Enter the name: John
// Enter the id: 1
// Enter the salary: 12000
// Enter the compensation: 1500
// Enter the period: hourly
// Name: John
// Id: 1
// Salary: 12000
// Compensation: 1500
// Period: hourly
// Enter the name: Rahaem
// Enter the id: 2
// Enter the salary: 15000
// Enter the compensation: 2000
// Enter the period: weekly
// Name: Rahaem
// Id: 2
// Salary: 15000
// Compensation: 2000
// Period: weekly
// Enter the name: Sam
// Enter the id: 3
// Enter the salary: 20000
// Enter the compensation: 2500
// Enter the period: monthly
// Name: Sam
// Id: 3
// Salary: 20000
// Compensation: 2500
// Period: monthly
// Enter the name: Vector
// Enter the id: 4
// Enter the salary: 25000
// Enter the compensation: 3000
// Enter the period: hourly
// Name: Vector
// Id: 4
// Salary: 25000
// Compensation: 3000
// Period: hourly
// Enter the name: Mufasa
// Enter the id: 5
// Enter the salary: 30000
// Enter the compensation: 3500
// Enter the period: weekly
// Name: Mufasa
// Id: 5
// Salary: 30000
// Compensation: 3500
// Period: weekly
// Enter the name: Simba
// Enter the id: 6
// Enter the salary: 35000
// Enter the compensation: 4000
// Enter the period: monthly
// Name: Simba
// Id: 6
// Salary: 35000
// Compensation: 4000
// Period: monthly




// class employee2
// {
//     protected:
//     string name;
//     int id;
//     public:
//     void getdata()
//     {
//         cout<<"Enter name: ";
//         cin>>name;
//         cout<<"Enter id: ";
//         cin>>id;
//     }
//     void putdata()
//     {
//         cout<<"Name: "<<name<<endl;
//         cout<<"Id: "<<id<<endl;
//     }
// };
// class manager2:public employee2
// {
//     public:
//     void getdata()
//     {
//         employee2::getdata();
//         cout<<"Enter the salary: ";
//         cin>>salary;
//     }
//     void putdata()
//     {
//         employee2::putdata();
//         cout<<"Salary: "<<salary<<endl;
//     }
//     double salary;
// };
// class scientist2:public employee2
// {
//     public:
//     void getdata()
//     {
//         employee2::getdata();
//         cout<<"Enter the salary: ";
//         cin>>salary;
//     }
//     void putdata()
//     {
//         employee2::putdata();
//         cout<<"Salary: "<<salary<<endl;
//     }
//     double salary;
// };
// class labour2:public employee2
// {
//     public:
//     void getdata()
//     {
//         employee2::getdata();
//         cout<<"Enter the salary: ";
//         cin>>salary;
//     }
//     void putdata()
//     {
//         employee2::putdata();
//         cout<<"Salary: "<<salary<<endl;
//     }
//     double salary;
// };
// int main()
// {
//     manager2 m;
//     scientist2 s;
//     labour2 l;
//     m.getdata();
//     m.putdata();
//     s.getdata();
//     s.putdata();
//     l.getdata();
//     l.putdata();
//     return 0;
// }
// Output:
// Enter name: John
// Enter id: 1
// Enter the salary: 10000
// Name: John
// Id: 1
// Salary: 10000
// Enter name: Jane
// Enter id: 2
// Enter the salary: 20000
// Name: Jane
// Id: 2
// Salary: 20000
// Enter name: Jack
// Enter id: 3
// Enter the salary: 30000
// Name: Jack
// Id: 3
// Salary: 30000
// 