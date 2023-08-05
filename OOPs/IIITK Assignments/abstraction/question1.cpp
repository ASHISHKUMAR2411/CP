// Example to show abstractions 
#include <iostream>
using namespace std;
class Addition
{ // declaring class for the program
public:
    // constructor
    Addition(int i = 0)
    { // constructor for class with the same name
        total = i;
    }
    // interface to outside world
    void numAdd(int number)
    { // add function to add values
        total += number;
    }
    // interface to outside world
    int getTotal()
    {
        return total;
    };

private:
    // hidden data from outside world
    int total;
};
int main()
{
    Addition ad;
    ad.numAdd(25);
    ad.numAdd(35);
    ad.numAdd(44);
    cout << " The Total of the number is  " << ad.getTotal() << endl;
    return 0;
}
