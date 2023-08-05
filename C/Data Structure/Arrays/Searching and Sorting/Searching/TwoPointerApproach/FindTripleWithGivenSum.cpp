// Finding triplets with given sum with O(n^2) time
#include<bits/stdc++.h>
using namespace std;
pair<int, int> FindPairWithGivenSum(int arr[], int low, int high, int sum){
    int sumPair = 0;
    while (low < high)
    {
        sumPair = arr[low] + arr[high];
        if (sumPair == sum)
        {
            return make_pair(low, high);
        }
        else if (sumPair < sum)
        {
            low++;
        }
        else
        {
            high--;
        }
    }
    return make_pair(-1, -1);
}

vector<int> FindTripletWithGivenSum(int arr[], int n, int sum){
    for (int i = 0; i < n-1;i++){
        pair<int, int> pair = FindPairWithGivenSum(arr, i+1, n-1, sum - arr[i]);
        if (pair.first != -1 && pair.second != -1)
        {
            // values 
            vector<int> triplet;
            triplet.push_back(arr[i]);
            triplet.push_back(arr[pair.first]);
            triplet.push_back(arr[pair.second]);
            // For index
            // vector<int> tripletIndex;
            // tripletIndex.push_back(i);
            // tripletIndex.push_back(pair.first);
            // tripletIndex.push_back(pair.second);
            return triplet;
        }
    }
    return vector<int>();
}
int main() {
    // same time complexity for sorted and unsorted
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 10;
    sort(arr, arr + n);
    vector<int> triplet = FindTripletWithGivenSum(arr, n, sum);
    if (triplet.size() == 0)
        cout << "Triplet not found";
    else
        cout << "Triplet are " << triplet[0] << " " << triplet[1] << " " << triplet[2];
    return 0;
}