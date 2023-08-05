// Find the pair with given sum 
#include<bits/stdc++.h>
using namespace std;
// Using hashing 
bool FindPairWithGivenSum(vector<int> &arr, int sum){
    unordered_set<int> set;
    for(int i: arr){
        if(set.find(sum - i) != set.end()){
            return true;
        }
        else{
            set.insert(i);
        }
    }
    return false;
}

int main()
{
    srand(time(0));
    vector<int> arr1;
    int n = rand() % 250;
    cout << n << "\n";
    for (int i = 0; i < n; i++)
    {
        arr1.push_back(rand() % 100);
    }
    for (int i : arr1)
    {
        cout << "->" << i;
    }
    cout << "\n";
    int sum = rand() % 100;
    if (FindPairWithGivenSum(arr1, sum))
    {
        cout << sum << " found " << endl;
    }
    else{
        cout << sum << " element not found \n";
    }
    return 0;
}