// CPP program to know brief about vectors data types 
// Vectors are same as dynamic arrays with the ability to resize itself automatically when an element is inserted or deleted, with their storage being handled automatically by the container. Vector elements are placed in contiguous storage so that they can be accessed and traversed using iterators. In vectors, data is inserted at the end. Inserting at the end takes differential time, as sometimes there may be a need of extending the array. Removing the last element takes only constant time because no resizing happens. Inserting and erasing at the beginning or in the middle is linear in time.

// Each vector object has two parameters–size and capacity. The size denotes the number of elements currently stored in the vector while capacity is the maximum number of elements that the vector can store without reallocation. Evidently capacity >= size. When the vector runs out of space to store new elements i.e when size is becoming greater than capacity, the runtime library will request fresh memory from the heap and once memory is allocated, it will copy all elements in the vector from their old addresses to the newly allocated memory address. A call to the function reserve modifies the capacity parameter of the vector and so the vector requests sufficient memory to store the specified number of elements.

// BEGIN () begin() function is used to return an iterator pointing to the first element of the vector container. begin() function returns a bidirectional iterator to the first element of the container.
// Time Complexity: O(1)

// ASSIGN () it is used to assign a particukar data to the no of element we want to too , in that we can loss our previous data . and we can alter the size of the array

// END () it return an iterator which points the vector at the element to the end of the vector . It is bidirectional
// Time Complexity: O(1)

// AT () is used to give the iterator or return the value at the At that position if it is not in range then it throws array ,
// CAPACITY () it return an integrer knowlege of how many element can vector store without new allocation of memory i.e how much space of the vector has used and then it might get deleted , the number of elements are either less than or equal to the capacity ;

// CBEGIN () it return an constant iterator which is pointing at the very first element of the vector .
// The function returns an iterator which is used to iterate container.

// The iterator points to the beginning of the vector.
// Iterator cannot modify the contents of the vector.
// Time Complexity: O(1)

// CEND () it return an constant iterator which is pointing one preceeding element , at the  end of the vector
// The function returns an iterator which is used to iterate container.

// The iterator points to past-the-end element of the vector.
// Iterator cannot modify the contents of the vector.
// Time Complexity: O(1)

// CLEAR () is the function where the vector it clears all the element but the it does not clear those element that contains the memeory address i.e which are pointer , clear not clear those element which contains the pointers ..

// CRBEGIN () function is the function which returns the iterator which is pointing to end of the vector plus the iterator is constant too ,...

// CREND () function  is the function which retrun the iterator constant to the beginning of the vector ..

// RBEGIN () vector::rbegin() is a built-in function in C++ STL which returns a reverse iterator pointing to the last element in the container.

// REND () vector::rend() is a built-in function in C++ STL which returns a reverse iterator pointing to the theoretical element right before the first element in the array container.

// SIZE () this is a function which return the size of the vectors.

// EMPTY () this stl function checks whether the vector is empty or not .

// empty() function is often said to be preferred over the size() function due to some of these points-

// empty() function does not use any comparison operators, thus it is more convenient to use
// empty() function is implemented in constant time, regardless of container type, whereas some implementations of size() function require O(n) time complexity such as list::size().

// MAXSIZE () The vector::max_size() is a built-in function in C++ STL which returns the maximum number of elements that can be held by the vector container.

// RESIZE () vector::resize()
// The function alters the container’s content in actual by inserting or deleting the elements from it. It happens so,
// vectorname.resize(int n, int val)
// If the given value of n is less than the size at present then extra elements are demolished.
// If n is more than current size of container then upcoming elements are appended at the end of the vector.

// SHRINK TO FIT () The vector::shrink_to_fit() is a built-in function in C++ STL which reduces the capacity of the container to fit its size and destroys all elements beyond the capacity.
// it will reduce the size but will not throw an error when we try to access the element out of range and it will give garbage value .

// RESERVE std::vector class provides a useful function reserve which helps user specify the minimum size of the vector.It indicates that the vector is created such that it can store at least the number of the specified elements without having to reallocate memory.

// SWAP () : This function is used to swap the contents of one vector with another vector of same type and sizes of vectors may differ.

// FRONT () used to resturn the value at the front of the vector

// BACK () used to return the value at te back of the vector .

// DATA () The std::vector::data() is an STL in C++ which returns a direct pointer to the memory array used internally by the vector to store its owned elements.

// NOTE : We can equate two vector of same typename
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define lli long long int
#define ulli unsigned long long int
#define endl '\n'
#define vi vector<int>
#define pi pair<int, int>
#define vii vector<pi>
#define f(i, m) for (int i = 0; i < m; i++)
#define fi(i, m) for (int i = 1; i <= m; i++)
#define fir(i, n, m) for (int i = n; i <= m; i++)
#define mo 1000000007
using namespace std;
int main()
{
    vector<string> Dynamic_Array = {"ASHISH", "SONY", "PRIYA", "RADHA"};
    vector<int> v = {1, 2, 3, 4};
    vector<int> v1 = {12, 32, 34, 45};
    vector<int> v2 = {11, 21, 31};
    for (auto iterator = Dynamic_Array.begin(); iterator != Dynamic_Array.end(); iterator++)
    {
        cout << " " << *iterator;
    }
    cout << endl;
    // Dynamic_Array.assign(2, "KonHai");
    // for (auto iterator = Dynamic_Array.begin(); iterator != Dynamic_Array.end(); iterator++)
    // {
    //     cout << " " << *iterator;
    // }
    // cout << endl;
    // for (auto iterator = Dynamic_Array.begin(); iterator != Dynamic_Array.end(); iterator++)
    // {
    //     cout << " " << *iterator;
    // }
    cout << Dynamic_Array.at(1);
    cout << endl;
    cout << Dynamic_Array.back();
    cout << endl;
    cout << *(Dynamic_Array.begin());
    cout << endl;
    cout << Dynamic_Array.capacity();
    cout << endl;
    // AS we can see here that after the cbegin which is a const iterator returning it has almost stooped the process after that
    // cout<<*(Dynamic_Array.cbegin());
    // cout<<endl;
    // cout<<*Dynamic_Array.cend();
    // cout<<endl;
    for (auto iterator = Dynamic_Array.cbegin(); iterator != Dynamic_Array.cend(); iterator++)
    {
        cout << " " << *iterator;
    }
    // THIS shows here that the element assign has just overwritten the vector but the vector still contain the element , but only it is not able to show with end() function because end of the vector is set to different value after the assign() function ..
    for (int i = 0; i < Dynamic_Array.capacity(); i++)
    {
        cout << "\n"
             << Dynamic_Array[i];
    }

    cout << "\n";
    // Dynamic_Array.clear();
    // clear() function clear all the element but we can still fetch them as we can see below but it almost stops the process after that

    // NOTE we cannot access element which is larger than the capacity of the vector because it give unexpected output.
    cout << Dynamic_Array[2] << "\n";
    // cout<<*Dynamic_Array.begin()<<"\n";

    // cout<<*(Dynamic_Array.crbegin()+2);

    for (auto iterator = Dynamic_Array.rbegin(); iterator != Dynamic_Array.rend(); iterator++)
    {
        cout << " " << *iterator;
    }
    cout << endl;
    for (auto iterator = Dynamic_Array.crbegin(); iterator != Dynamic_Array.crend(); iterator++)
    {
        cout << " " << *iterator;
    }
    cout << "\n"
         << Dynamic_Array.size();
    cout << "\n"
         << Dynamic_Array.empty();
    cout << "\n"
         << Dynamic_Array.max_size();
    Dynamic_Array.resize(5);
    for (auto iterator = Dynamic_Array.crbegin(); iterator != Dynamic_Array.crend(); iterator++)
    {
        cout << "\n " << *iterator;
    }
    cout << "\n"
         << Dynamic_Array.capacity();
    v.resize(6);
    cout << "\n"
         << v.capacity();
    for (auto iterator = v.crbegin(); iterator != v.crend(); iterator++)
    {
        cout << "\n " << *iterator;
    }
    v.resize(7, 9);
    cout << "\n"
         << v.capacity();
    for (auto iterator = v.crbegin(); iterator != v.crend(); iterator++)
    {
        cout << "\n " << *iterator;
    }
    v.resize(5);
    for (auto iterator = v.begin(); iterator != v.end(); iterator++)
    {
        cout << " " << *iterator;
    }
    cout << "\n"
         << v[6];
    v.shrink_to_fit();
    // now it will give us some garbage value .
    cout << "\n"
         << v[6];
    cout << "\n"
         << v.capacity() << endl;
    // IT swaps the value of v2 to v1 and vice versa , it does not depend on size;
    v1.swap(v2);
    for (auto iterator = v1.begin(); iterator != v1.end(); iterator++)
    {
        cout << " " << *iterator;
    }
    for (auto iterator = v2.begin(); iterator != v2.end(); iterator++)
    {
        cout << " " << *iterator;
    }
    cout << "\n"
         << v1.front() << " " << v1.back() << "\n";
    string *ptr = Dynamic_Array.data();
    cout << " value at 2 is " << *(ptr + 2) << endl;
}