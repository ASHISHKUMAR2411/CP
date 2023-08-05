// Program for Addition of Matrix
#include <bits/stdc++.h>
#include <chrono>
using std::vector;
using std::cout;
using namespace std::chrono;
int m = rand() % 10 + 1;
int n = rand() % 10 + 1;
// Function to add two matrices
vector<vector<int> > addition(vector<vector<int> > &mat1, vector<vector<int> > &mat2)
{
    vector<vector<int> > res(m, vector<int>(n, 0));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            res[i][j] += mat1[i][j] + mat2[i][j];
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
    vector<vector<int>> arr1;
    vector<vector<int>> arr2;
    
    InputMatrix(arr1, m , n);
    InputMatrix(arr2, m , n);
    cout << "Matrix 1\n";
    OutputMatrix(arr1);
    cout << "\n";
    cout << "Matrix 2\n";
    OutputMatrix(arr2);
    cout << "\n";
    auto start = high_resolution_clock::now();
    vector<vector<int> > res = addition(arr1, arr2);
    auto stop = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "Method took " << duration.count() << " nanosecond\n";
    cout << "Addition of Matrix\n";
    OutputMatrix(res);
    return 0;
}
Matrix 1
76 12 46 16 84 64 70 
6 68 86 96 89 48 1 
82 71 90 33 92 25 90 
94 96 51 98 48 99 25 

Matrix 2
82 65 98 57 76 44 24 
12 7 94 17 27 31 65 
15 78 65 48 48 7 32 
91 31 73 36 27 24 34 

Method took 2722 nanosecond
Addition of Matrix
158 77 144 73 160 108 94 
18 75 180 113 116 79 66 
97 149 155 81 140 32 122 
185 127 124 134 75 123 59 

Matrix 1
57 38 91 83 44 87 22 
58 26 24 49 5 59 49 
43 3 27 92 88 86 63 
29 19 100 80 54 60 29 

Matrix 2
75 99 14 83 88 56 65 
32 94 38 41 19 61 89 
76 71 90 18 25 16 61 
65 1 76 45 71 75 24 

Method took 3613 nanosecond
Addition of Matrix
132 137 105 166 132 143 87 
90 120 62 90 24 120 138 
119 74 117 110 113 102 124 
94 20 176 125 125 135 53 
