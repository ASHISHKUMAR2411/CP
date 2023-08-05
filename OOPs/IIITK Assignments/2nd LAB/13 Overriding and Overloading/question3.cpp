// Write a C++ Program to Suppose that you need to define classes for employee and manager objects. An employee has a name, an employee code, salary and age. A manager is also an employee. But a manager object contains an additional list of references to employee objects that the manager supervises. An employee object should also contain a reference to his/her manager. A manager can supervise at most 10 employees. It is required to print details of employee or a manager. When information of an employee object is printed, his/her name, salary and age is printed. When information of a manager object is printed, his/her name, salary and age is printed and names of all the employees that he/she supervises are displayed. Define the classes keeping the following in mind:
// (a) References to employee objects can be added/deleted from the list of supervised employees in a manager object.
// (b) Reference to the manager object can be modified for an employee object.
#include<bits/stdc++.h>
using namespace std;
class employee
{
    string name;
    int code;
    float salary;
    int age;
    public:
    employee()
    {
        name="";
        code=0;
        salary=0;
        age=0;
    }
    employee(string n,int c,float s,int a)
    {
        name=n;
        code=c;
        salary=s;
        age=a;
    }
    void getdata()
    {
        cout<<"Enter name: ";
        cin>>name;
        cout<<"Enter code: ";
        cin>>code;
        cout<<"Enter salary: ";
        cin>>salary;
        cout<<"Enter age: ";
        cin>>age;
    }
    void putdata()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Code: "<<code<<endl;
        cout<<"Salary: "<<salary<<endl;
        cout<<"Age: "<<age<<endl;
    }
};
class manager:public employee
{
    int n;
    employee *e[10];
    public:
    manager()
    {
        n=0;
        for(int i=0;i<10;i++)
        {
            e[i]=NULL;
        }
    }
    manager(string n,int c,float s,int a):employee(n,c,s,a)
    {
        n=0;
        for(int i=0;i<10;i++)
        {
            e[i]=NULL;
        }
    }
    void getdata()
    {
        employee::getdata();
        cout<<"Enter number of employees: ";
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cout<<"Enter name of employee "<<i+1<<": ";
            string name;
            cin>>name;
            cout<<"Enter code of employee "<<i+1<<": ";
            int code;
            cin>>code;
            cout<<"Enter salary of employee "<<i+1<<": ";
            float salary;
            cin>>salary;
            cout<<"Enter age of employee "<<i+1<<": ";
            int age;
            cin>>age;
            e[i]=new employee(name,code,salary,age);
        }
    }
    void putdata()
    {
        employee::putdata();
        cout<<"Number of employees: "<<n<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<"Employee "<<i+1<<endl;
            e[i]->putdata();
        }
    }
};
int main()
{
    manager m;
    m.getdata();
    m.putdata();
    return 0;
}
// Output:
// Enter name: John
// Enter code: 1
// Enter salary: 10000
// Enter age: 25
// Enter number of employees: 2
// Enter name of employee 1: Jane
// Enter code of employee 1: 2
// Enter salary of employee 1: 20000
// Enter age of employee 1: 20
// Enter name of employee 2: Jack
// Enter code of employee 2: 3
// Enter salary of employee 2: 30000
// Enter age of employee 2: 30
// Name: John
// Code: 1
// Salary: 10000
// Age: 25
// Number of employees: 2
// Employee 1
// Name: Jane
// Code: 2
// Salary: 20000
// Age: 20
// Employee 2
// Name: Jack
// Code: 3
// Salary: 30000
// Age: 30
//