#include<bits/stdc++.h>
using namespace std;

// to create our own data structure
struct bag{
    int minVal, maxVal;
    bag(){
        minVal = INT_MAX;
        maxVal = INT_MIN;
    }
    void insert(int x){
        minVal = min(minVal, x);
        maxVal = max(x, maxVal);
    }
    void minimum(){
        return minVal;
    }
    void maximum(){
        return maxVal;
    }
};
// it works only when either a is sorted or partitoned at val. 
bool Binary_search(int arr[], int l, int h, int val){
    return binary_search(arr + l, arr + h + 1, val);
}
int main(){
    vector<int> a = {12, 5, 3, 5, 5, 3, 12, 2, 2, 18, 2};
    sort(a.begin(), a.end());
    int lenght = unique(a.begin(), a.end()) - a.begin();
    // the lower bound finds the elements from l to r which is >= val, it return the position as address
    cout << lower_bound(a.begin(), a.end(), 6) << endl;
    // the distance function find the posiiton in number
    cout << distance(a.begin(), lower_bound(a.begin(), a.end(), 6));
    for (int i = 0; i < lenght; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}