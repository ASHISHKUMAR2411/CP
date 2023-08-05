// CPP program to convert the string  to char array in c++
// Method 1 
// A way to do this is to copy the contents of the string to char array. This can be done with the help of c_str() and strcpy() function of library cstring. 
//NOTE: The c_str() function is used to return a pointer to an array that contains a null terminated sequence of character representing the current value of the string.
// Syntax: 

// const char* c_str() const ;
// If there is an exception thrown then there are no changes in the string.
// NOTE : But when we need to find or access the individual elements then we copy it to a char array using strcpy() function. After copying it, we can use it just like a simple array. 
// The length of the char array taken should not be less than the length of input string.  

#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    string s = "ASHISH KUMAR ";
    int size = s.length();
    char array[size+1];
    strcpy(array,s.c_str());
    for(int i =0;i<size;i++)
    {
        cout<<" "<<array[i];
    }
    return 0;
}