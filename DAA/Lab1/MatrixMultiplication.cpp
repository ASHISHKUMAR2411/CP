// Program for Multiplication of Matrix
#include <bits/stdc++.h>
#include <chrono>
using std::vector;
using std::cout;
using namespace std::chrono;

// Function to  Multiply two matrices
vector<vector<int> > Multiply(vector<vector<int> > &A, vector<vector<int> > &B)
{
    vector<vector<int>> res(A.size(), vector<int>(B[0].size(), 0));
    for (int i = 0; i < A.size(); i++){
        for (int j = 0; j < B[0].size(); j++){
            for (int k = 0; k < A[0].size(); k++){
                res[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return res;
}

// Function to Take the input matrix
void InputMatrix(vector<vector<int>> &arr, int m, int n){
    arr.resize(m, vector<int>(n, 0));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            arr[i][j] = rand() % 100 + 1;
        }
    }
}

// Function to print the matrix
void OutputMatrix(vector<vector<int> > &arr){
    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < arr[i].size(); j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

// Driver Program
int main(){
    srand(time(0));
    int m1 = rand() % 10 + 1;
    int n1 = rand() % 10 + 1;
    int n2 = rand() % 10 + 1;
    vector<vector<int>> arr1;
    vector<vector<int>> arr2;
    
    InputMatrix(arr1, m1 , n1);
    InputMatrix(arr2, n1 , n2);
    auto start = high_resolution_clock::now();
    vector<vector<int> > res = Multiply(arr1, arr2);
    auto stop = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "Matrix 1\n";
    OutputMatrix(arr1);
    cout << "\n";
    cout << "Matrix 2\n";
    OutputMatrix(arr2);
    cout << "\n";
    cout << "Method took " << duration.count() << " nanosecond\n";
    cout << "Multiplication of Matrix\n";
    OutputMatrix(res);
    return 0;
}

// Matrix 1
// 42 38 46 87 76 86 
// 94 24 62 93 81 74 
// 15 96 25 7 59 31 
// 70 94 63 72 9 91 
// 95 54 88 8 21 23 
// 30 62 60 28 49 35 

// Matrix 2
// 13 94 11 
// 75 38 91 
// 100 52 39 
// 24 10 97 
// 6 31 91 
// 20 55 51 

// Method took 4691 nanosecond
// Multiplication of Matrix
// 12260 20483 17505 
// 12260 20483 17505 
// 12260 20483 17505 
// 12260 20483 17505 
// 12260 20483 17505 
// 12260 20483 17505 

// Matrix 1
// 73 30 30 96 1 
// 26 99 79 44 49 
// 63 94 100 14 39 

// Matrix 2
// 64 62 13 1 72 18 
// 56 48 95 74 6 15 
// 36 80 21 71 4 51 
// 52 99 51 29 98 29 
// 72 46 43 17 97 56 

// Method took 5097 nanosecond
// Multiplication of Matrix
// 12496 17916 9368 7224 15061 6134 
// 15868 19294 15753 15070 11847 10002 
// 16432 19598 14240 15188 10655 10234 
