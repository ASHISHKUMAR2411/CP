// In C++ using vector by knowing this that it copies all the content to another array and extend the size to double when it size is full, so the best way to ignore such scenario when u already know the size of the vector, so we should reserve for the vector which is fast and safe;

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n = 5;
    vector<int> vec;
    vec.reserve(n);
    for(int i = 0; i < n; i++){
        vec.push_back(i);
    }
    for(int i = 0; i < n; i++){
        cout << vec[i] << " ";
    }
    cout << "\n";
}