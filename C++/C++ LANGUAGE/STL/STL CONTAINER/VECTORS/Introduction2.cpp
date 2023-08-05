// CPP program to know more about the modifier of the vectors

// ASSIGN vector:: assign() is an STL in C++ which assigns new values to the vector elements by replacing old ones. It can also modify the size of the vector if necessary. vectorname.assign(int size, int value)

// PUSHBACK vector::push_back()
// push_back() function is used to push elements into a vector from the back. The new value is inserted into the vector at the end, after the current last element and the container size is increased by 1.

// POPBACK  vector::pop_back()()
// pop_back() function is used to pop or remove elements from a vector from the back. The value is removed from the vector from the end, and the container size is decreased by 1.

// INSERT std::vector::insert() is a built-in function in C++ STL which inserts new elements before the element at the specified position, effectively increasing the container size by the number of elements inserted. 
// vector_name.insert (position, val)
// Return value: The function returns an iterator which points to the newly inserted element.

// vector_name.insert(position, size, val)
// Return value: The function returns an iterator which points to the newly inserted element.

// vector_name.insert(position, iterator1, iterator2)
// Return value: The function returns an iterator which points to the newly inserted element.

// CLEAR  vector::clear()
// clear() function is used to remove all the elements of the vector container, thus making it size 0.
// vectorname.clear()
// Time Complexity: O(N) 
// Time Complexity: O(N2) in the worst case as an erase takes linear time.

// clear() vs erase(), When to use what?
// clear() removes all the elements from a vector container, thus making its size 0. All the elements of the vector are removed using clear() function. 
// erase() function, on the other hand, is used to remove specific elements from the container or a range of elements from the container, thus reducing its size by the number of elements removed.

// ERASE vector::erase()
// 1. vectorname.erase(position)
// 2. vectorname.erase(startingposition, endingposition)
// erase() function is used to remove elements from a container from the specified position or range.

// EMPLACE The vector::emplace() is an STL in C++ which extends container by inserting new element at position. Reallocation happens only if there is a need of more space. Here the container size increases by one.

// The advantage of emplace is, it does in-place insertion and avoids an unnecessary copy of object. For primitive data types, it does not matter which one we use. But for objects, use of emplace() is preferred for efficiency reasons.

// Syntax:
// Return value: The function returns an iterator which points to the newly inserted element.
// template 
// iterator vector_name.emplace (const_iterator position, element);

// EMPLACEBACK vector::emplace_back()
// This function is used to insert a new element into the vector container, the new element is added to the end of the vector.
// Syntax :
// Time Complexity: O(1)
// vectorname.emplace_back(value)

// emplace_back() vs push_back()
// push_back() copies a string into a vector. First, a new string object will be implicitly created initialized with provided char*. Then push_back will be called which will copy this string into the vector using the move constructor because the original string is a temporary object. Then the temporary object will be destroyed.

// emplace_back() constructs a string in-place, so no temporary string will be created but rather emplace_back() will be called directly with char* argument. It will then create a string to be stored in the vector initialized with this char*. So, in this case, we avoid constructing and destroying an unnecessary temporary string object.


#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v1 = {1, 2, 3};
    for (auto it = v1.begin(); it != v1.end(); it++)
    {
        cout << " " << *it;
    }
    cout << endl;
    // v1.assign(5);
    v1.resize(4);
    for (auto it = v1.begin(); it != v1.end(); it++)
    {
        cout << " " << *it;
    }
    cout << endl;
    v1.push_back(1);
    v1.push_back(3);
    for (auto it = v1.begin(); it != v1.end(); it++)
    {
        cout << " " << *it;
    }
    cout << endl;
    v1.pop_back();
    for (auto it = v1.begin(); it != v1.end(); it++)
    {
        cout << " " << *it;
    }
    // popback only reduces the size of the vector 
    cout << "\n" << v1[5];
    v1.shrink_to_fit();
    cout << "\n" << v1[5]<<"\n";
    auto it = v1.insert(v1.begin()+2 , 9);
    cout<<" "<<*it<<" "<<"\n ";
    for (auto it = v1.begin(); it != v1.end(); it++)
    {
        cout << " " << *it;
    }
    cout<<endl;
    for (auto it : v1)
        cout << it << " ";
    it = v1.insert(v1.begin()+2,3,-1);
    v1.insert(v1.begin(),2,0);
    cout<<endl;
    for (auto it = v1.begin(); it != v1.end(); it++)
    {
        cout << " " << *it;
    }
    cout<<endl;
    // we can also insert value of one vector into other using insert 
    // ?for e,g
    vector<int> v2;
    v2.insert(v2.begin(),v1.begin()+1,v1.begin()+5);
    for (auto it = v2.begin(); it != v2.end(); it++)
    {
        cout << " " << *it;
    }
    cout<<endl;
    v1.erase(v1.begin()+1,v1.begin()+3);
    for (auto it = v1.begin(); it != v1.end(); it++)
    {
        cout << " " << *it;
    }
    cout<<endl;
    v1.erase(v1.begin()+5);
    // v1.clear();
    for (auto it = v1.begin(); it != v1.end(); it++)
    {
        cout << " " << *it;
    }
    cout<<endl;
    it = v1.emplace(v1.begin(),10);
    it = v1.emplace(v1.begin()+3,15);
    it = v1.emplace(v1.end(),16);
    for (auto it = v1.begin(); it != v1.end(); it++)
    {
        cout << " " << *it;
    }
    cout<<endl;
    v1.emplace_back(12);
    for (auto it = v1.begin(); it != v1.end(); it++)
    {
        cout << " " << *it;
    }
    cout<<endl;
    
}