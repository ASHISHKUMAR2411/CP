// Given 20*20 matrix find for each element in the matrix the highest product of 4 adjacent elements in all directions(right, left, up, down, four diagonals)


// I have considered maxProduct = 0 if there are no 4 adjacent elements in any direction. and if product goes out of range , I have taken modulo with 1000000007.
#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

// function for FInding the max product of 4 adjacent elements in all directions
vector<vector<int>> FindMatrix(vector<vector<int>> &arr){
    vector<vector<int>> matrix(arr.size(), vector<int>(arr.size()));
    for (int i = 0; i < arr.size(); i++){
        for (int j = 0; j < arr[i].size(); j++){
            int max = INT_MIN;
            int product = 1;
            // horizontal left
            if(j - 3 >= 0){
                for (int k = 0; k < 4; k++){
                    product = (product * 1ll * arr[i][j - k]) % mod;
                }
                max = max > product ? max : product;
            }
            // horizontal right
            product = 1;
            if(j + 3 < arr[i].size()){
                for (int k = 0; k < 4; k++){
                    product = (product * 1ll * arr[i][j + k]) % mod;
                }
                max = max > product ? max : product;
            }
            // vertical up
            product = 1;
            if(i - 3 >= 0){
                for (int k = 0; k < 4; k++){
                    product = (product * 1ll * arr[i - k][j]) % mod;
                }
                max = max > product ? max : product;
            }
            // vertical down
            product = 1;
            if(i + 3 < arr.size()){
                for (int k = 0; k < 4; k++){
                    product = (product * 1ll * arr[i + k][j]) % mod;
                }
                max = max > product ? max : product;
            }
            // diagonal left up
            product = 1;
            if(i - 3 >= 0 && j - 3 >= 0){
                for (int k = 0; k < 4; k++){
                    product = (product * 1ll * arr[i - k][j - k]) % mod;
                }
                max = max > product ? max : product;
            }
            // diagonal left down
            product = 1;
            if(i + 3 < arr.size() && j - 3 >= 0){
                for (int k = 0; k < 4; k++){
                    product = (product * 1ll * arr[i + k][j - k]) % mod;
                }
                max = max > product ? max : product;
            }
            // diagonal right up
            product = 1;
            if(i - 3 >= 0 && j + 3 < arr[i].size()){
                for (int k = 0; k < 4; k++){
                    product = (product * 1ll * arr[i - k][j + k]) % mod;
                }
                max = max > product ? max : product;
            }
            // diagonal right down
            product = 1;
            if(i + 3 < arr.size() && j + 3 < arr[i].size()){
                for (int k = 0; k < 4; k++){
                    product = (product * 1ll * arr[i + k][j + k]) % mod;
                }
                max = max > product ? max : product;
            }
            if (max == INT_MIN)
                max = 0;
            matrix[i][j] = max;
        }
    }
    return matrix;
}

// Printing the matrix
void PrintMatrix(vector<vector<int>> &arr){
    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < arr[i].size(); j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// Input of Matrix
void InputMatrix(vector<vector<int>> &arr){
    int row  = 20;
    arr.resize(row);
    for (int i = 0; i < row; i++){
        arr[i].resize(row);
        cout << "Enter the elements of row " << i+1 << " : ";
        for (int j = 0; j < row; j++){
            cin >> arr[i][j];
        }
    }
    return;
}

// Driver Code
int main(){
    vector<vector<int>> arr;
    InputMatrix(arr);
    cout << "Matrix before finding the max product of 4 adjacent elements in all directions : " << endl;
    PrintMatrix(arr);
    vector<vector<int>> matrix = FindMatrix(arr);
    cout << "The Resultant Matrix is : " << endl;
    PrintMatrix(matrix);
    return 0;
}

