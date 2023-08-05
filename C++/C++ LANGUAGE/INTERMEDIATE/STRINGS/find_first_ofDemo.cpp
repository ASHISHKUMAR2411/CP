// C++ program to demonstrate
// the use of std::find_first_of

// By comparing using a pre-defined function:
// Syntax:

// Template
//    ForwardIterator1 find_first_of (ForwardIterator1 first1,
//                                    ForwardIterator1 last1,
//                                    ForwardIterator2 first2,
//                                    ForwardIterator2 last2,
//                                    BinaryPredicate pred);

// Here, first1, last1, first2 and last2 are the same as
// previous case.

// Pred: Binary function that accepts two
// elements as arguments (one of each of the two sequences,
// in the same order), and returns a value convertible to
// bool. The value returned indicates whether the elements
// are considered to match in the context of this function.
// The function shall not modify any of its arguments.
// This can either be a function pointer or a function object.

// Return Value: It returns an iterator to
// the first element in [first1,last1) that is part of
// [first2,last2). If no matches are found or [first2,last2)
// is empty, the function returns last1.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Defining the BinaryFunction
bool Pred(int a, int b)
{
    if (a % b == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    // Defining first container
    vector<int> v = {1, 5, 7, 11, 13, 15, 30, 30, 7}, i;

    // Defining second container
    vector<int> v1 = {2, 3, 4};

    vector<int>::iterator ip;

    // Using std::find_first_of
    ip = std::find_first_of(v.begin(), v.end(), v1.begin(),
                            v1.end(), Pred);

    // Displaying the first element satisfying Pred()
    cout << *ip << "\n";

    return 0;
}
