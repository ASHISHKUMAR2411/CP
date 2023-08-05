// ConcatStringWithwscatFunction
// C++ program to demonstrate
// example of wcscat() function.

#include <bits/stdc++.h>
using namespace std;

int main()
{

	// maximum length of the destination string
	wchar_t dest[30];

	// maximum length of the source string
	wchar_t src[30];

	// initialize the destination string
	wcscpy(dest, L"Geekforgeeks ");

	// initialize the source string
	wcscpy(src, L"is the best");


	wcscat(dest, src);
	wprintf(L"%ls\n", dest);
	return 0;
}
