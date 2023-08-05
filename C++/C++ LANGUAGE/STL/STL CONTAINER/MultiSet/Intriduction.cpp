// In Multiset is actually every feature of set but the extra feature is that it can hold same element more than once.

// A multiset is a associative container which stores duplicate data and sort them into ascending order by default
// We can also store different data type for set but we always need to add comparator fuction for thr data to be compared before being push to the set.

// Syntax: set<T, func> setname;
// By Default it is greater<>

// NOTES:
// 1. std::set is an Associative Container that contains a sorted set of unique objects of type Key.
// 2. It is usually implemented using Red-Black Tree.
// 3. Insertion, Removal, Search have logarithmic complexity.
// 4. If we want to store user defined data type in set then we will have to provide compare function so that set can store them in sorted order.
// 5. We can pass the order of sorting while constructing set object.

// BOTTOM LINE:
// It store unique elements and they are stored in sorted order (A/D)

// The value of the elements in a multiset cannot be modified once in the container (the elements are always const), but they can be inserted or removed from the container.

#include<iostream>
#include<set>
#include<functional>
#include<string>
using namespace std;
class Person{
    public :
        int number;
        string name;
        bool operator<(const Person &obj) const { return obj.number > number; }
        bool operator>(const Person &obj) const { return obj.number < number; }
};
int main(){
    multiset<int> ms = {1, 2, 3, 4, 2, 3, 6, 4, 2, 1};
    for(auto &a: ms){
        cout << a << " ";
    }
    cout << "\n";
    multiset<Person, std::greater<Person>> MS{{24, "Ashish"}, {21, "Aka"}, {54, "PKA"}};
    for (auto &a : MS)
    {
        cout << a.name << " " << a.number << "\n";
    }
    cout << "\n";
}