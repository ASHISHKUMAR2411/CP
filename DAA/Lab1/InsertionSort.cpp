// Program to implement the Insertion Sort
// taking random inputs at runtime using rand() function to test the algorithm.
#include <bits/stdc++.h>
#include <chrono>
using std::cout;
using std::vector;
using namespace std::chrono;

void InsertionSort(vector<int> &vec){
    for (std::size_t j = 1; j < vec.size(); j++){
        int key = vec[j];
        int i = j - 1;
        while (i >= 0 && vec[i] > key){
            vec[i + 1] = vec[i];
            i--;
        }
        vec[i + 1] = key;
    }
}

void Output(vector<int> &arr){
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << "\n";
}

// Driver program to test above function
int main(){
    srand(time(0));
    vector<int> arr;
    int n = rand() % 10 + 1;
    cout << n << "\n";
    for (int i = 0; i < n; i++)
        arr.push_back(rand() % 100 + 1);
    Output(arr);
    cout << "\n";
    auto start = high_resolution_clock::now();
    InsertionSort(arr);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "Sorted Array: \n";
    Output(arr);
    cout << "Method took " << duration.count() << " nanosecond\n";
}

// 69, 8, 17, 45, 79, 43, 5, 84, 99, 6, 98, 24, 15, 34, 28, 28, 97, 81, 36, 69, 56, 63, 89, 11, 25

// 7 62 41 42 50 31 52 38

    // 31 38 41 42 50 52 62 Method took 1098 nanosecond
// 10 1 68 64 57 63 94 99 33 80 77

//     Sorted Array : 1 33 57 63 64 68 77 80 94 99 Method took 920 nanosecond
