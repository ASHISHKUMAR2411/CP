// Given an array of no of pages of each book and we have k students , distribute the book in continuous manner such that the maximum pages read by a student is minimum.
#include <bits/stdc++.h>
using namespace std;
int sum(int arr[], int b, int e)
{
    int sum = 0;
    for (int i = b; i <= e; i++)
    {
        sum += arr[i];
    }
    return sum;
}
// naive solution
int minPages(int arr[], int n, int k)
{
    if (k == 1)
        return sum(arr, 0, n - 1);
    if (n == 1)
        return arr[0];
    int res = INT_MAX;
    for (int i = 0; i <= n - k; i++)
    {
        res = min(res, max(minPages(arr, i, k - 1), sum(arr, i, n - 1)));
    }
    return res;
}

// O(n) solution
bool Feasible(int arr[], int n, int k, int ans)
{
    int req = 1, sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum + arr[i] > ans)
        {
            req++;
            sum = arr[i];
        }
        else
            sum += arr[i];
    }
    return req <= k;
}

int MinimumPages(int arr[], int n, int k)
{
    int sum = 0, mx = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        mx = max(mx, arr[i]);
    }
    int l = mx, r = sum, res = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (Feasible(arr, n, k, mid))
        {
            r = mid - 1;
            res = mid;
        }
        else
            l = mid + 1;
    }
    return l;
}

int main()
{
    int books = {10, 30, 20, 40, 50, 60, 70, 80, 90, 100};
    int n = sizeof(books) / sizeof(books[0]);
    int k = 3;
    cout << minPages(books, n, k);
    return 0;
}
