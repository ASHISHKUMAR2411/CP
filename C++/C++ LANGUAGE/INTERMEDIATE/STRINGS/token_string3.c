// CPP program to find the token of the string and print it accordingly 
// Using strtok_r() 
// Using strtok_r()
// Just like strtok() function in C, strtok_r() does the same task of parsing a string into a sequence of tokens. strtok_r() is a reentrant version of strtok().
// There are two ways we can call strtok_r() 
 

// The third argument saveptr is a pointer to a char * 
// variable that is used internally by strtok_r() in 
// order to maintain context between successive calls
// that parse the same string.
// char *strtok_r(char *str, const char *delim, char **saveptr);
// C/C++ program to demonstrate working of strtok_r()
// by splitting string based on space character.
#include<stdio.h>
#include<string.h>

int main()
{
	char str[] = "Geeks for Geeks";
	char *token;
	char *rest = str;

	while ((token = strtok_r(rest, " ", &rest)))
		printf("%s\n", token);

	return(0);
}
