// In this we have a range and we have put all number between the range together and smaller on the left side and larger on after them using Dutch National Flag Algorithm
#include <bits/stdc++.h>
using namespace std;
void PartitionRange(int arr[], int n, int lowV, int highV)
{
    int low = 0, mid = 0, high = n - 1;
    int temp = highV;
    if (lowV > highV)
    {
        highV = lowV;
        lowV = temp;
    }
    cout << "From : " << lowV << " to : " << highV << endl;
    while (mid <= high)
    {
        if (arr[mid] < lowV)
        {
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        else if (arr[mid] > highV)
        {
            swap(arr[mid], arr[high]);
            high--;
        }
        else
        {
            mid++;
        }
    }
}
int main()
{
    int n = 25;
    int arr[n];
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand();
        cout << arr[i] << " ";
    }
    cout << endl;
    PartitionRange(arr, n, rand(), rand());
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}