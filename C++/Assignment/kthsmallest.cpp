// Program to find the kth smallest element in an array in CPP
#include<bits/stdc++.h>
using namespace std;


// this function returns the kth smallest element in the array
int findKthSmallest(vector<int> &arr, int k){
    set<int> s(arr.begin(), arr.end());
    auto itr = s.begin(); // s.begin() returns a pointer to first// element in the set
    advance(itr, k - 1); // itr points to kth element in set
    return *itr;
}

// function to take input as Array
void inputVector(vector<int> &arr, int &k){
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;
    arr.resize(n);
    cout << "Enter the elements : ";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout<<endl;
    cout<<"Enter the value of k to find kth smallest element: ";
    cin >> k;
    if(arr.size() < k){
        cout << "Invalid Input";
        exit(1);
    }
    return;
}

// main function
int main()
{
    int k;
    vector<int> arr;
    inputVector(arr, k);
    cout << findKthSmallest(arr, k) << endl;
    return 0;
}