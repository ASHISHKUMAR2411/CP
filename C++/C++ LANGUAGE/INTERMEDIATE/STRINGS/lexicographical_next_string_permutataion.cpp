// CPP program to find the lexicographical  next string to find the next string  
#include<bits/stdc++.h>
using namespace std;
void swap(char* a, char* b)
{
    if (*a == *b)
        return;
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}
void rev(string& s, int l, int r)
{
    while (l < r)
        swap(&s[l++], &s[r--]);
}

int bsearch(string& s, int l, int r, int key)
{
    int index = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (s[mid] <= key)
            r = mid - 1;
        else {
            l = mid + 1;
            if (index == -1 || s[index] >= s[mid])
                index = mid;
        }
    }
    return index;
}
bool nextPermutation(string &s)
{
    int len = s.length(), i = len - 2;
    while (i >= 0 && s[i] >= s[i + 1])
        --i;
    if (i < 0)
        return false;
    else {
        int index = bsearch(s, i + 1, len - 1, s[i]);
        swap(&s[i], &s[index]);
        rev(s, i + 1, len - 1);
        return true;
    }

}
int main()
{
    string s;
    cout<<"\nenter the string whose next permuataion is used to find ";
    cin>>s;
    bool found = nextPermutation(s);
    if(found == false)
    {
        cout<<"\nNOT FOUND !";
    }
    else
    {
        cout<<"\n next string is  "<<s<<endl;
    }
    return 0;
}