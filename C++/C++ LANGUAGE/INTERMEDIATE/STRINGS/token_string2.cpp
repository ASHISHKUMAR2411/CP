// CPP program to tokenising the string Using strtok()
// Splits str[] according to given delimiters.
// and returns next token. It needs to be called
// in a loop to get all tokens. It returns NULL
// when there are no more tokens.
// char * strtok(char str[], const char *delims);
#include<bits/stdc++.h>
using namespace std;
int main()
{
    char str[ ] = "Ashish-kumar-is-studing-in-IIIT-KOTA";
    char *token = strtok(str,"-");
    while(token!=NULL) 
    {
        printf("%s\n",token);
        token = strtok(NULL,"-");
    }
    return 0;
}