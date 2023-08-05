// StringToUpperCaseUsingTransformFunction
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s("Ashish");
    transform(s.begin(),s.end(),s.begin(),[](unsigned char c)->unsigned char{return toupper(c);});
    vector<size_t> ordinals;
    transform(s.begin(),s.end(),back_inserter(ordinals),[](unsigned char c)->size_t{return c;});
    cout<<" "<<s<<":";
    for(auto ord : ordinals)
    {
        cout<<" "<<ord;
    }
    transform(ordinals.cbegin(),ordinals.cend(),ordinals.cbegin(),ordinals.begin(),plus<>{});
    cout<<"\n";
    for(auto ord : ordinals)
    {
        cout<<ord<<" ";
    }
    cout<<"\n";
}
