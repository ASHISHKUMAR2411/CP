// CPP program to show the static_cast functioning

// Static Cast: This is the simplest type of cast which can be used. It is a compile time cast.It does things like implicit conversions between types (such as int to float, or pointer to void*), and it can also call explicit conversion functions (or implicit ones)

#include <iostream>
using namespace std;
int main()
{
    float f = 3.5;
    int a = f;                   // this is how you do in C
    int b = static_cast<int>(f); // this is what we do in C++
    char ch = 'A';
    cout << b << " " << a << " ";
    b = static_cast<int>(ch);
    cout << b << " " << a << " ";
    string c = "Ashish";
    // Not possible 
    // c = static_cast<string>((string)b);
    cout << b << " " << c << " ";
    ch = static_cast<char>(f);// it will give a heart 
    for(int i =0;i<10;i++)
    {
        cout<<"\n";
        for(int j = 0 ;j<10;j++)
        {
            if((j+i)%7 == 0)
            {
                cout<<" ";
            }
            else
            {
                cout<<ch;
            }
        }
    }
    cout << f << " " << ch << " ";
    ch = static_cast<char>(b+5);
    cout << b << " " << ch << " ";
    return 0;
}
