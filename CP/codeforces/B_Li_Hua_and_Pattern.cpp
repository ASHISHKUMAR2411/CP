#include <bits/stdc++.h>
using namespace std;

int count_ways_to_make_array_good(vector<int> &arr)
{
    int n = arr.size();
    int A = arr[0];
    int B = arr[n - 1];
    int k = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (arr[i] > A)
        {
            k++;
        }
    }
    long long ways = 1;
    for (int i = 1; i <= k; i++)
    {
        ways = (ways * i) % 1000000007;
    }
    return ways;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = count_ways_to_make_array_good(arr);
    cout << ans << endl;
    return 0;
}