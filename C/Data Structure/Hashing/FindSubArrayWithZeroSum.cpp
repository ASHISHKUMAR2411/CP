// Find the array with given sum 
#include <bits/stdc++.h>
using namespace std;
// O(n) time complexity and O(n) space complexity
bool FindSubarrayWithSumZero(vector<int> &arr){
    unordered_set<int> set;
    int prefix_sum = 0;
    for(int i : arr){
        prefix_sum += i;
        if(set.find(prefix_sum) != set.end()){
            return true;
        }
        else{
            set.insert(prefix_sum);
        }
    }
    return false;
}

int main(){
    int n = 10;
    vector<int> arr{1, 4, 13, -3, -10, 5};
    if(FindSubarrayWithSumZero(arr)){
        cout << " Yes ";
    }
    else{
        cout << " No ";
    }
    return 0;
}