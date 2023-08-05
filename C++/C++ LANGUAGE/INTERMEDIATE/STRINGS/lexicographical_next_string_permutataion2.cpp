// CPP programt tofind the lexicographical next word to your
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    string s;
    cout << "\nenter the string :";
    cin >> s;
    bool value = next_permutation(s.begin(), s.end());
    if (value == false)
    {
        cout << "\nno next word find";
    }
    else
    {
        cout << "\nThe string is : " << s;
    }
    return 0;
}