// CPP prgram to tokenise the string 
// Tokenizing a string denotes splitting a string with respect to some delimiter(s). There are many ways to tokenize a string. In this article four of them are explained:
// Using stringstream
// we will seperate the string with respect to the space between them 

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string line = "Ashish kumar studies in IIIT KOTA ";
    vector<string> token;
    stringstream check1(line);
    string intermediate;
    // token w.r.t ' ' 
    while(getline(check1,intermediate,' '))
    {
        token.push_back(intermediate);
    }
    for(int i=0;i<token.size();i++)
    {
        cout<<token[i]<<endl;
    }
}