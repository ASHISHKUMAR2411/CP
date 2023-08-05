// C++ program to demonstrate
// postfix increment operator overloading

#include <bits/stdc++.h>
using namespace std;

class Integer
{
private:
    int i;

public:
    // Parameterised constructor
    Integer(int i = 0)
    {
        this->i = i;
    }

    // Overloading the postfix operator
    Integer operator++(int)
    {
        Integer temp;
        temp.i = i++;
        return temp;
    }

    Integer operator++()
    {
        Integer temp;
        temp.i = ++i;
        return temp;
    }

    // Function to display the value of i
    void display()
    {
        cout << "i = " << i << endl;
    }
};

// Driver function
int main()
{
    Integer i1(3);

    cout << "Before increment: ";
    i1.display();

    // Using the post-increment operator
    Integer i2 = i1++;

    cout << "After post increment: ";
    i2.display();
    Integer i3 = ++i1;

    cout << "After pre increment: ";
    i3.display();
}
