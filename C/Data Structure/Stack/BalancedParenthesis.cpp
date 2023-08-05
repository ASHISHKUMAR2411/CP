// Balanced Parenthesis is a string which contains ("()","{}","[]") only and it is following that the bracket which open last should close first 
// for ex of balanced parenthesis is : {}[()], (()),([]) etc ... 
#include<bits/stdc++.h>
using namespace std;
bool IsBalanced(string const &s){
    stack<char> st;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            st.push(s[i]);
        }
        else{
            if(s[i] == ')'){
                if(st.top() == '(')
                    st.pop();
                else return false;
            }
            else if(s[i] == '}'){
                if(st.top() == '{')
                    st.pop();
                else return false;
            }
            else if(s[i] == ']'){
                if(st.top() == '[')
                    st.pop();
                else return false;
            }
            else{
                return false;
            }
        }
    }
    if(st.empty())
        return true;
    return false;
}

int main() {
    vector<char> bracket{"(", "{", "[", "]", "}", ")"};
    string s = "{}[()]";
    if(IsBalanced(s)){
        cout << "Yes";
    }
    else
        cout << "No";
    return 0;
}