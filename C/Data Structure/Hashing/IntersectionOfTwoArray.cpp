// C++ Program to find the intersection of two array using hash 
// It's a O(n) and O(n) time and space respectively
#include<bits/stdc++.h>
using namespace std;
void Intersection(vector<int> &arr1, vector<int> &arr2){
    unordered_set<int> set;
    for(int i : arr1){
        set.insert(i);
    }
    cout << endl;
    for(int i : arr2){
        if(set.find(i) != set.end()){
            cout << i << " ";
            set.erase(i);
        }
    }
}

int main(){
    srand(time(0));
    vector<int> arr1;
    int n = rand() % 250;
    cout << n << "\n";
    for (int i = 0; i < n; i++)
    {
        arr1.push_back(rand() % 25);
    }
    for (int i : arr1)
    {
        cout << "->" << i;
    }
    cout << "\n";
    vector<int> arr2;
    n = rand() % 250;
    cout << n << "\n";
    for (int i = 0; i < n; i++)
    {
        arr2.push_back(rand() % 25);
    }
    for (int i : arr2)
    {
        cout << "->" << i;
    }
    cout << "\n";
    Intersection(arr1, arr2);
    return 0;
}