#include <bits/stdc++.h>
using namespace std;
void fibo(int n, int a, int b)
{
    if (n <= 1)
    {
        cout << a << " ";
        return;
    }
    cout << a << " ";
    fibo(n - 1, b, a + b);
}
int main()
{
    // cout << 0 << " ";
    fibo(7, 0, 1);
}