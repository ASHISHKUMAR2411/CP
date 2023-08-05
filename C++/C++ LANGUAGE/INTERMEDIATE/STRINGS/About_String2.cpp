// C++ program to show working
// of get_allocator function
#include <iostream>
#include <vector>

using namespace std;

// Function for allocating
char *Allocate(vector<char> arr, int size)
{
    // allocate space for size(s) elements
    return arr.get_allocator().allocate(size);
}

void Construct(vector<char> arr,
               char *point, int size)
{
    for (int iter = 0; iter < size; ++iter)

        // construct values in-place on the array:
        arr.get_allocator().construct(&point[iter],
                                      iter + 97);
}

// Function for Deallocating
void deAllocate(vector<char> arr,
                char *point, int size)
{
    for (int iter = 0; iter < size; ++iter)
        arr.get_allocator().destroy(&point[iter]);

    // free allocated memory
    arr.get_allocator().deallocate(point, size);
}

// Function that using string::npos
// to find the index of the occurrence
// of any string in the given string
void fun(string s1, string s2)
{
    // Find position of string s2
    int found = s1.find(s2);

    // Check if position is -1 or not
    if (found != string::npos)
    {

        cout << "first " << s2
             << " found at: "
             << int(found) << endl;
    }

    else
        cout << s2 << " is not in"
             << "the string" << endl;
}
// Driver code
int main()
{
    vector<char> array;
    char *pointer;
    int size = 8;

    pointer = Allocate(array, size);
    Construct(array, pointer, size);

    cout << "Array elements: ";
    for (int iter = 0; iter < size; ++iter)
        cout << pointer[iter] << " ";

    deAllocate(array, pointer, size);

    string str1 = "Ashish Kumar";
    // str1.npos
    string s1 = "geeksforgeeks";
    string s2 = "for";
    string s3 = "no";

    // Function Call
    fun(s1, s2);
    cout << "\n";
    int find = s1.find(s2);
    // it is always is used as string::npos
    if (find != string::npos)
    {
        cout << "found";
    }

    // str1.operator+=()
    // str1.operator=()
    str1.~basic_string();
    cout << str1;

    return 0;
}
