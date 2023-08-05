#include <iostream>
using namespace std;
// ! we ahve to traverse the array only once in order to do that
void swapping(int &ele1, int &ele2)
{
    int temp = ele1;
    ele1 = ele2;
    ele2 = temp;
}
void sort01(int arr[], int size)
{
    int left = 0, right = size - 1;
    while (left < right)
    {
        if (arr[left] == 0)
        {
            left++;
        }
        else if (arr[right] == 1)
        {
            right--;
        }
        if (arr[left] == 1 && arr[right] == 0)
        {
            swapping(arr[left], arr[right]);
        }
    }
}
void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        /* code */
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[100], count;
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        /* code */
        cin >> arr[i];
    }
    sort01(arr, count);
    print(arr, count);
    return 0;
}