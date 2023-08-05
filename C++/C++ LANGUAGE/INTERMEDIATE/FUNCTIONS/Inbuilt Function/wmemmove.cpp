// wmemmove
#include<iostream>
#include<bits/stdc++.h>
#include<cwchar.h>

using namespace std;
int main()
{
    wchar_t *des = L"Ashish Kumar is in House ";
    wchar_t des_l[wcslen(des)+1];
    wchar_t *src = L"Indian Institute Of Information Technology";
    wchar_t src_l[wcslen(src)+1];
    wcscpy(des_l,des);
    wprintf(L"Destination : %ls\n",des);
    wcscpy(src_l,src);
    wprintf(L"Source : %ls\n",src);
    wmemmove(des+1,src+1,20);
    wprintf(L"Now the changes made in is : %ls\n",des);
    return 0;
}
