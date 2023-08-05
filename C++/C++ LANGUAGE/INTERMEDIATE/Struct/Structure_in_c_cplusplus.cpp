// C++ Program to Implement Member functions inside
// structure

// Direct Initialization: We cannot directly initialize structure data members in C but we can do it in C++.

// Static Members: C structures cannot have static members but is allowed in C++.

#include<iostream>
using namespace std;
struct marks
{
    int num;
    void Set(int temp) // Member function inside Structure to
    {                  // take input and store it in "num
        num = temp;
    }
    void display() // function used to display the values
    {
        cout << "num = " << num;
    }
};
struct Student
{
    int roll;
    Student(int x)
    {
        roll = x;
    }
};
// Driver Program
int main()
{
    struct Student s(2);
    printf("%d\n", s.roll);
    marks m1;
    m1.Set(9);    // calling function inside Struct to
                  // initialize value to num
    m1.display(); // calling function inside struct to
                  //   display value of Num
                  //  The default type of  sizeof  is long unsigned int , that’s why  “%lu” is used instead of “%d” in printf function.
    printf("\n%lu\n", sizeof(s));
}

// This Code is Contributed by Samyak Jain
