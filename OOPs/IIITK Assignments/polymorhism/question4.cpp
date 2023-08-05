// C++ program to show binary operator overloading
#include <iostream>

using namespace std;

class Number
{
public:
    // Member Object
    int a, b;
    // No Parameter Constructor
    Number()
    {
        this->a = 0;
        this->b = 0;
    }

    // Constructor to initialize the object's value
    // Parameterized Constructor
    Number(int f, int i)
    {
        this->a = f;
        this->b = i;
    }

    // Overloading (+) operator to perform addition of
    // two Number object
    Number operator+(Number &d2) // Call by reference
    {
        // Create an object to return
        Number d3;

        // Perform addition of feet and bes
        d3.a = this->a + d2.a;
        d3.b = this->b + d2.b;

        // Return the resulting object
        return d3;
    }
    Number operator-(Number &d2) // Call by reference
    {
        Number d3;
        d3.a = this->a - d2.a;
        d3.b = this->b - d2.b;
    }

    Number operator*(Number &d) // Call by reference
    {
        Number d3;
        d3.a = this->a * d.a;
        d3.b = this->b * d.b;
    }

    Number operator/(Number &d2) // Call by reference
    {
        Number d3;
        d3.a = this->a / d2.a;
        d3.b = this->b / d2.b;
    }
};

// Driver Code
int main()
{
    // Declaring and Initializing first object
    Number d1(8, 9);

    // Declaring and Initializing second object
    Number d2(10, 2);

    // Declaring third object
    Number d3;

    // Use overloaded operator
    d3 = d1 + d2;
    cout << "\n Value after sum is : " << d3.a << " " << d3.b<<endl;

    d3 = d1 - d2;
    cout << "\n Value after minus is : " << d3.a<<" " << d3.b <<endl;
    
    d3 = d1 * d2;
    cout << "\n Value after multiplication is : " << d3.a << " " << d3.b<<endl;

    d3 = d1 / d2;

    cout << " \n Value after divide is : " << d3.a << " " << d3.b<<endl;

    // Display the result
    return 0;
}
