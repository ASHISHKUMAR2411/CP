#include <iostream>
using namespace std;
int main()
{
    long num, temp;
    int oct[50], i = 1, j;
    cout << "Enter a decimal number : ";
    cin >> num;
    temp = num;
    while (temp != 0)
    {
        oct[i++] = temp % 8;
        temp = temp / 8;
    }
    cout << "\nOctal equivalent of " << num << " is : ";
    for (j = i - 1; j >= 0; j--)
        cout << oct[j];
    return 0;
}
