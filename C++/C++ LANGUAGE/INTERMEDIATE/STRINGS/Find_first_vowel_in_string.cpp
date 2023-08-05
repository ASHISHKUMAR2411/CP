// CPP program to find the first vowel using find_first_of
// in this we are using find_first_of
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int count = 0;
    string str1 = "Ashish beta we have to try more hard as this is not enough ek bar mehnat kar lo then every thing will be possible for you ";
    string str2 = {'a','A','i','I','e','E','o','O','u','U'};
    auto ip = str1.begin();
    while(ip!= str1.end())
    {
        ip = find_first_of(ip,str1.end(),str2.begin(),str2.end());
        count++;
        cout<<" the "<<count<<" vowel find is : "<<*ip<<"  at position : "<<(ip-str1.begin())<<"\n";
        ip = ip + 1;
    }
    return 0;
}