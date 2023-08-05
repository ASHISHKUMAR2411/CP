// FLT_RADIX
// C++ program to demonstrate
// example of scalbn() function.

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n = 7;
	int x = 5;
	int ans;

	ans = scalbn(x, n);
	cout << x << " * "
		<< FLT_RADIX << "^"
		<< n << " = "
		<< ans << endl;

	return 0;
}
