// Program to find the distint element in an array 
// using hashing O(n) space and time complexity
#include<bits/stdc++.h>
using namespace std;
int FindNumberOfDistinctElement(vector<int> &arr){
    unordered_set<int> set;
    for(int i : arr){
        set.insert(i);
    }
    return set.size();
}
int main(){
    srand(time(0));
    vector<int> arr;
    int n = rand() % 100;
    cout << n << "\n";
    for (int  i = 0; i < n; i++)
    {
        arr.push_back(rand() % 100);
    }
    for(int i : arr){
        cout << "->" << i;
    }
    cout << "\n";
    cout << "Distinct elements are " << FindNumberOfDistinctElement(arr) << "\n";
}
