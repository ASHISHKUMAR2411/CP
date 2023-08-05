// C++ Program to Add Two Complex Numbers

// Importing all libraries
#include <bits/stdc++.h>
using namespace std;

// User Defined Complex class
class Complex
{
private:
    // Declaring variables
    int real, imaginary;

public:
    // Constructor to accept
    // real and imaginary part
    Complex()
    {
        real = 0;
        imaginary = 0;
    }
    
    void Initialise(){
        cout<<"enter the real and imaginary parts"<<endl;
        cin>>real>>imaginary;
    }
    void ShowComplex(){
        // printing  complex number
        cout << "Complex number is : " << real<< " + i" << imaginary << endl;
    }
    // Defining addComp() method
    // for adding two complex number
    Complex addComp(Complex C1, Complex C2)
    {
        // creating temporary variable
        Complex temp;
        // adding real part of complex numbers
        temp.real = C1.real + C2.real;

        // adding Imaginary part of complex numbers
        temp.imaginary = C1.imaginary + C2.imaginary;

        // returning the sum
        return temp;
    }
};

// Main Class
int main()
{

    // First Complex number
    Complex C1;
    // Second Complex number
    Complex C2;
    C1.Initialise();
    C2.Initialise();
    // for Storing the sum
    Complex C3;
    C1.ShowComplex();
    C2.ShowComplex();
    // calling addComp() method
    C3 = C3.addComp(C1, C2);
    // printing the sum
    C3.ShowComplex();
}
