// CPP program to show how const_cast is used to change the const value , but we have to keep in mind that once const decalred then its value can be chab=nged and it is not possibe to change if you will see the approach then you will understand

// It is undefined behavior to modify a value which is initially declared as const. Consider the following program. The output of the program is undefined. The variable ‘val’ is a const variable and the call ‘fun(ptr1)’ tries to modify ‘val’ using const_cast.

// #include <iostream>
// using namespace std;
// In this value of val does not chnage 
// int fun(int *ptr)
// {
//     *ptr = *ptr + 10;
//     return (*ptr);
// }

// int main(void)
// {
//     const int val = 10;
//     const int *ptr = &val;
//     int *ptr1 = const_cast<int *>(ptr);
//     cout << fun(ptr1)<<"\n";
//     cout << val;
//     return 0;
// }

#include <iostream>
using namespace std;
//  In this value of val changes 
int fun(int* ptr)
{
	*ptr = *ptr + 10;
	return (*ptr);
}

int main(void)
{
	int val = 10;
	const int *ptr = &val;
	int *ptr1 = const_cast <int *>(ptr);
	fun(ptr1);
	cout << val;
	return 0;
}

