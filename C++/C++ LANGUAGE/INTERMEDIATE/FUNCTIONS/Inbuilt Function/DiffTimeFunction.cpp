// DiffTimeFunction
// C++ program to demonstrate
// example of difftime() function.
/* 
The difftime() function is defined in ctime header file. The difftime() function is used to calculate the difference between two times in second.

Syntax:

double difftime(time_t end, time_t start);
Parameters: This method accepts two parameters:

start: time_t object for start time.
end: time_t object for end time.
Returns: This function returns the difference between two times in seconds.
 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
	time_t start, ending;
	long addition;

	time(&start);
	for (int i = 0; i < 20000; i++) {
		for (int j = 0; j < 20000; j++);
	}
	for (int i = 0; i < 20000; i++) {
		for (int j = 0; j < 20000; j++);
	}
	for (int i = 0; i < 20000; i++) {
		for (int j = 0; j < 20000; j++);
	}
	time(&ending);
	cout << "Total time required = "
		<< difftime(ending, start)
		<< " seconds " << endl;
	return 0;
}
