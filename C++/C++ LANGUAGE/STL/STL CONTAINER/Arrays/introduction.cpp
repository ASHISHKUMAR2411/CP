// In array template are like classic array in C where the size is predefined for the array.

// syntax is : std::array<T,N> arr; where the N is the size of the array, and the T is the typename

// as array is actually a class inside the stl library where it create an object arr with an actually C type array with defined size N, and also have some member fuction associated with it. 

//NOTICE:
// 1. std::array is a container that encapsulates fixed size arrays.
// 2. array size is needed at compile time.
// 3. Assign by value is actually by value.
// 4. Access Elements:
//    a. at()
//    b. []
//    c. front()
//    d. back()
//    e. data() // gives access to the underlying array, it actually give the inner pointer to the array 

#include<iostream>
#include<array>
// #include<gsl>
using namespace std;
// using namespace gsl;

// if uou don't know the type
void PrintArr1(auto &arr){
    for(auto& a : arr){
        cout << a << " ";
    }
    cout << endl;
}

// using template
template<std::size_t N> void PrintArr2(array<int , N> &arr){
    for (auto &a : arr)
    {
        cout << a << " ";
    }
    cout << endl;
}

// using pointers
template<typename T> void PrintArr3(T first, T last){
    for (;first!=last;first++){
        cout << *first << " ";
    }
    cout << endl;
}


int main(){
    array<int, 5> arr1 = {1, 2, 3, 4, 5};
    array<int, 4> arr2{1, 2, 3, 4};
    array<int, 3> arr3;
    arr3 = {1,2,3}
    PrintArr1(arr1);
    PrintArr2(arr3);
    PrintArr3(arr2.begin(), arr2.end());

}
