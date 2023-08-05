// CopyStringWithNullTerminatedUsingwscpyFunction
// C++ program to demonstrate
// example of wcscpy() function.

#include <bits/stdc++.h>
using namespace std;

int main()
{

	// maximum length of the destination string
	wchar_t dest[40];

	// initialize the source string
	wchar_t src[]=L"A computer science portal for geeks";

// Print the source string
	wcout << L"Source: " << src << endl;

// Print the destination string
	wcout << L"Destination: " << dest << endl;

// Copy source to destination
	wcscpy(dest, src);

// Print the modified destination
	wcout << L"After modification, destination: " << dest;

	return 0;
}
