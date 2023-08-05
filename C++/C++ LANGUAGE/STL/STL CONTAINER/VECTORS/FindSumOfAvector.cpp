// Finding the sum of the vector using stl
// we can also use partial sum to do the same but it provide another feature to store the result into another array
// accumulate uses numeric header file which also contains iota, partial_sum, reduce
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
// syntax : accumulate(first_index, last_index, initial value of sum, function);
// O(n) time complexity

// syntax ffor partial sum
// partial_sum(first, last, b);
// or
// partial_sum(first, last, b, myfun);
long int func(int x, int y)
{
    return x * y;
}

long int myFunc(int x, int y){
    return x + 2 * y;
}
int main()
{
    vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << " sum is : " << accumulate(arr.begin(), arr.end(), 0);
    cout << endl;
    // we can also manipulate accumulate in different ways
    cout << "minus sum is " << accumulate(arr.begin(), arr.end(), 0, std::minus<int>());
    cout << endl;
    // using function to manipulate accumulate
    cout << "Multiplication is : " << accumulate(arr.begin(), arr.end(), 1, func);
    cout << endl;
    int b[arr.size()];
    // vector<int> b(arr.size());
    // cout << b.size();
    partial_sum(arr.begin(), arr.end(), b);
    for (int i = 0; i < arr.size(); i++){
        cout << b[i] << " ";
    }
    int c[arr.size()];
    partial_sum(b, b + arr.size(), c, myFunc);
    cout << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << c[i] << " ";
    }
}