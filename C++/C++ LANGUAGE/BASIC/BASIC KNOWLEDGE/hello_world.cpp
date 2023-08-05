#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    vector<string> msg { "hello","C++","World","From","VSCODE","and","learning","debug"};
    for(const string& word:msg)
    {
        cout<< word <<" ";
    }
    cout<<endl;
    return 0;
}