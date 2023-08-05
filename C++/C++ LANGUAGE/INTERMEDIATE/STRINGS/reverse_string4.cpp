// CPP program to find the reverse string PART 4
// in this we are using swap to reverse
#include <bits/stdc++.h>
using namespace std;
char *reverse_string(const char *str)
{
    int size = strlen(str);
    // here we are using extra space for doing the process which is not a good thing in coding
    char *rev = new char[size + 1];
    strcpy(rev, str);
    for (int i = 0, j = size - 1; i < j; i++, j--)
    {
        swap(rev[i], rev[j]);
    }
    return rev;
}
int main()
{
    // in this we are using const string or const strng pointer
    const char *str = "ASHISH KUMAR";
    cout << reverse_string(str);
    return 0;
}