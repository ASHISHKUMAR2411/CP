#include <bits/stdc++.h>
#include <chrono>
using std::cout;
using std::vector;
using namespace std::chrono;

int findSubarraySum(vector<int> &arr)
{
    unordered_map<int, int> prevSum;
    int res = 0;
    int currsum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        currsum += arr[i];
        if (currsum == 0)
            res++;
        if (prevSum.find(currsum) != prevSum.end())
            res += (prevSum[currsum]);
        prevSum[currsum]++;
    }
    return res;
}

void Output(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

// Driver program to test above function
int main()
{
    srand(time(0));
    vector<int> arr;
    int n = rand() % 10 + 1;
    cout << n << "\n";
    for (int i = 0; i < n; i++)
    {
        arr.push_back(rand() % 100 + 1);
    }
    Output(arr);
    cout << "\n";
    auto start = high_resolution_clock::now();
    cout << findSubarraySum(arr, 0, arr.size() - 1) <<"\n";
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "Method took " << duration.count() << " nanosecond\n";
}