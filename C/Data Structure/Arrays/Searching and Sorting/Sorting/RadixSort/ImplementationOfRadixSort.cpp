// Radix sort is a sorting technique where we have the range of element as k same as Counting Sort but it works with large value of k also like range wise 
// Time complexity is O(N+K)
// Space Complexity is O(n+k)
// Required is : n should be small

#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
void CountingSort(int arr[], int n, int k);
// Radix Sort
void RadixSort(int arr[], int n)
{
    int maxi = *max_element(arr, arr + n);
    for (int i = 1; maxi/i > 0 ; i *= 10){
        CountingSort(arr, n, i);
    }
}
void CountingSort(int arr[], int n, int k){
    int count[10] = {0,0,0,0,0,0,0,0,0,0}, output[n];
    for(int i = 0; i < n; i++){
        count[(arr[i] / k) % 10]++;
    }
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--){
        output[count[(arr[i]/k)%10] - 1] = arr[i];
        count[(arr[i] / k) % 10]--;
    }
    for (int i = 0; i < n;i++){
        arr[i] = output[i];
    }
}
int main(){
    srand(time(0));
    auto start = high_resolution_clock::now();
    int n = 1000;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand();
        cout << arr[i] << " ";
    }
    cout << endl;
    RadixSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << duration.count() << endl;
    return 0;
}


