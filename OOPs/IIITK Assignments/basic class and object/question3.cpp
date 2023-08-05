#include <iostream>
using namespace std;
class parent
{
private:
    int p;

protected:
    int q;

public:
    int r;
    parent() //constructor to initialize data members
    {
        p = 100;
        q = 200;
        r = 300;
    }
};
//Inheritance concept
class child : public parent
{
    //q becomes protected and r becomes public members of class child
public:
    void showdata()
    {
        cout << "p is not accessible" << endl;
        cout << "value of q is " << q << endl;
        cout << "value of r is " << r << endl;
    }
};
int main()
{
    child c; //object of derived class(child)
    c.showdata();
    //c.p = 100;   invalid : private member,no access
    //c.q = 200;   invalid : q is now private member of child class
    //c.r = 300;   invalid : r is also now a private member of child class
    return 0;
}
