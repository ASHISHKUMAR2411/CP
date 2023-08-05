// find the maximum occurring elements in the 2D array, and if all elements are unique print Unique

#include<bits/stdc++.h>
using namespace std;

// Function to find the maximum occuring element in the 2D array
void FindOccurrence(vector<vector<int>> &arr){
    unordered_map<int, int> m;
    int max = 0;
    for (int i = 0; i < arr.size(); i++){
        for (int j = 0; j < arr[i].size(); j++){
            m[arr[i][j]]++;
            if(m[arr[i][j]] > max)
                max = m[arr[i][j]];
        }
    }
    if(max > 1){
        for (auto itr = m.begin(); itr != m.end(); itr++){
            if(itr->second == max)
                cout << "ELement : " << itr->first << " Occurs " << itr->second << " Times" << endl;
        }
    }
    else{
        cout << "Unique";
    }
    return;
}

// function to take input as Matrix
void InputMatrix(vector<vector<int>> &arr){
    int row, col;
    cout << "Enter the number of rows : ";
    cin >> row;
    arr.resize(row);
    for (int i = 0; i < row; i++){
        cout << "Enter Row " << i + 1 << " ELements : ";
        arr[i].resize(row);
        for (int j = 0; j < row; j++){
            cin >> arr[i][j];
        }
    }
    return;
}

// main function
int main() {
    vector<vector<int>> arr;
    InputMatrix(arr);
    if(arr.size() == 0){
        cout << "Invalid Input,\n Matrix should not be Empty" << endl;
        exit(1);
    }
    FindOccurrence(arr);
    return 0;
}