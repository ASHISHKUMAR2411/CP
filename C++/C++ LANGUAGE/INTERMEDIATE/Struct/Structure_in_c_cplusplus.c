// *Member functions inside structure: Structures in C cannot have member functions inside structure but Structures in C++ can have member functions along with data members.
// C Program to Implement Member functions inside structure

// ? if we save as .cpp file then it works but it does not work with the .c file extension as in c it is not allowed to function inside the struct 
#include <stdio.h>
struct marks {
	int num;
	void
	Set(int temp) // Member function inside Structure to
					// take input and store it in "num"
	{
		num = temp;
	}
	void display() // function used to display the values
	{
		printf("%d", num);
	}
};
// Driver Program
int main()
{
	struct marks m1;
	m1.Set(9); // calling function inside Struct to
			// initialize value to num
	m1.display(); // calling function inside struct to
				// display value of Num
}

/* Error Occured
prog.c:18:4: error: ‘struct marks’ has no member named ‘Set’
m1.Set(9); // calling function inside Struct to
initialize value to num
	^
prog.c:19:4: error: ‘struct marks’ has no member named
‘display’ m1.display(); // calling function inside struct to
display value of Num
*/
