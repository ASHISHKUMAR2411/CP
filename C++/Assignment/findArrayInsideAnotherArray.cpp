#include<bits/stdc++.h>
using namespace std;
// as pattern elements can be same 

// function to find the pattern
bool FindPatterInsideMatrix(vector<vector<int>> &arr, vector<int> &pat){
    int j = 0;
    for (int i = 0; i < arr.size(); i++){
        // for checking each row
        int k = 0;
        for(int j = 0; j < arr[i].size(); j++){
            while(j < arr[i].size() && k < pat.size() && arr[i][j] == pat[k]){
                j++;
                k++;
            }
            if(k == pat.size()){
                return true;
            }
            else{
                j = j - k;
                k = 0;
            }
        }

        // for checking each column
        k = 0;
        for(int j = 0; j < arr[i].size(); j++){
            while(j < arr[i].size() && k < pat.size() && arr[j][i] == pat[k]){
                j++;
                k++;
            }
            if(k == pat.size()){
                return true;
            }
            else{
                j = j - k;
                k = 0;
            }
        }
    }
    return false;
}

// function to take input as Array
void inputVector(vector<vector<int>> &arr, vector<int> &pat){
    int n, m;
    cout << "Enter the number of rows : ";
    cin >> n;
    m = n;
    arr.resize(n);
    for (int i = 0; i < n; i++){
        arr[i].resize(m);
    }
    cout << "\n Enter the elements : ";
    for (int i = 0; i < n; i++){
        cout << "\nEnter the elements of row " << i+1 << " : ";
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    cout<<endl;
    cout<<"Enter the number of elements in pattern : ";
    cin >> m;
    pat.resize(m);
    if(arr.size() < pat.size()){
        cout << "Invalid Input length of pattern is greater" << endl;
        exit(1);
    }
    cout << "\nEnter the elements : ";
    for (int i = 0; i < m; i++){
        cin >> pat[i];
    }
    cout<<endl;
    return;
}

// function to print the matrix
void printMatrix(vector<vector<int>> &arr){
    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < arr[i].size(); j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}


// main function
int main()
{
    vector<vector<int>> arr;
    vector<int> pat;
    inputVector(arr, pat);
    if(FindPatterInsideMatrix(arr, pat)){
        cout << "Yes" << endl;
    }
    else{
        cout << "Pattern not found" << endl;
    }
    return 0;
}