// In this we have to make sure that the array is partitioned with positive and negative on other sides
#include <bits/stdc++.h>
using namespace std;
void PartitionPositiveNegative(int arr[], int n)
{
    int i = -1, j = n;
    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < 0);
        do
        {
            j--;
        } while (arr[j] > 0);
        if (i >= j)
            return;
        swap(arr[i], arr[j]);
    }
}
int main()
{
    int n = 25;
    int arr[n];
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() - 10000;
        cout << arr[i] << " ";
    }
    cout << endl;
    PartitionPositiveNegative(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}