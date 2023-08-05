// Given an Array Find the longest Sequence o present in the array
// Using hash table

#include <bits/stdc++.h>
using namespace std;

int LongestSequence(vector<int> &arr){
    int curr = 1, res = 1;
    unordered_set<int> set;
    for(int i : arr)
        set.insert(i);
    cout << "\n";
    for(int i = 0; i < arr.size(); i++){
        if(set.find(arr[i] - 1)== set.end()){
            curr = 1;
            cout << "\n" << arr[i];
            while(set.find(arr[i]+curr)!=set.end()){
                cout << " " << arr[i] + curr;
                curr++;
            }
            res = max(res, curr);
        }
    }
    return res;
}

int main(){
    srand(time(0));
    vector<int> arr;
    int n = rand() % 250;
    cout << n << "\n";
    for (int i = 0; i < n; i++){
        arr.push_back(rand() % 100);
    }
    for(int i : arr)
        cout << i << " ";
    int p = LongestSequence(arr);
    cout << "\n Longest Subsequence is : \n " << p;
    return 0;
}