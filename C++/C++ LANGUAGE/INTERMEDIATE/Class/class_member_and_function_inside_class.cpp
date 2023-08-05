#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lli long long int
#define ulli unsigned long long int
#define endl '\n'
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define f(i,m) for(int i = 0 ; i<m;i++)
#define fi(i,m) for(int i = 1 ; i<=m;i++)
#define fir(i,n,m) for(int i = n ; i<=m;i++)
using namespace std;
class company
{
    private:
    int id ;
    string name;
    float salary;
    public:
    company() {
        // cout<<"No employees in this object : ";
        this->id = 0;
        this->name = "";
        this->salary= 0.0;
    }
    void insert(int ID , string NAME, float SALARY)
    {
        this->id = ID;
        this->name = NAME;
        this->salary = SALARY;
    }
    void display()
    {
        cout<<"ID is : "<<id<<endl;
        cout<<"Name is : "<<name<<endl;
        cout<<"Salary is : "<<salary<<endl;
    }
};
int main()
{
    int id;
    string name;
    float salary;
    company ob[10];
    f(i,10)
    {
        cout<<"enter the id : ";
        cin>>id;
        cout<<"enter the name :";
        getline(cin,name);
        getline(cin,name);
        cout<<"enter the salary : ";
        cin>>salary;
        ob[i].insert(id,name,salary);
    }
    cout<<"now the detail of the employees are : "<<endl;
    f(i,10)
    {
        ob[i].display();
    }
    return 0;
}