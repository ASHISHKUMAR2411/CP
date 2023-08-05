// A set is a associative container which stores unique data and sort them into ascending order by default
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

#include<iostream>
#include<set>
#include<functional>
using namespace std;

class Object{
    public:
        int number; // number
        string name; // name
        bool operator<(const Object& other) const { 
            return number < other.number;
        }
        bool operator>(const Object& other) const {
            return number > other.number;
        }
};

int main(){
    set<int, std::greater<int>> SET = {1, 2, 3, 4, 5, 1, 2, 3, 6, 7};
    for(auto &e : SET){
        cout << e << " ";
    }
    cout << "\n";

    // now for a object
    set<Object, std::less<Object>> OBJECT = {{111, "Ashish Kumar"}, {12, "Prince"}, {3, "I Love Myself"}};
    for(auto &e : OBJECT){
        cout << e.name << " " << e.number << "\n";
    }
    
}