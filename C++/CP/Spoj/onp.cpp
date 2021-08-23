#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lli long long int
#define endl '\n'
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define MAX 1000000 
using namespace std;
int precedence(char symbol)
{
    if (symbol == '^')
    {
        return 5;
    }
    else if (symbol == '*')
    {
        return 4;
    }
    else if (symbol == '/')
    {
        return 3;
    }
    else if (symbol == '+')
    {
        return 2;
    }
    else if (symbol == '-')
    {
        return 1;
    }
    else
        return 0;
}
int main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
    {
        string infix ,dummy,postfix;
        char temp , symbol;
        int index = -1;
        int n, i = 0, position = 0;
        cin>>infix;
        n = infix.length();
        while (i < n)
        {
            symbol = infix[i];
            switch (symbol)
            {
            case '(':
                if (index >= 400)
                    ;
                else
                {
                    index++;
                    dummy.push_back(symbol);
                }
                break;
            case ')':
                if (index == -1)
                {
                    break;
                }
                else
                {
                    temp = dummy[index];
                    index--;
                }
                while (temp != '(')
                {
                    postfix.push_back(temp);
                    // postfix[position++] = temp;
                    if (index == -1)
                    {
                        break;
                    }
                    else
                    {
                        temp = dummy[index];
                        index--;
                    }
                }
                break;
            case '+':
            case '-':
            case '/':
            case '*':
            case '^':
                while (precedence(dummy[index]) >= precedence(symbol))
                {
                    if (index == -1)
                    {
                        break;
                    }
                    else
                    {
                        temp = dummy[index];
                        index--;
                    }
                    if (temp == '(')
                    {
                        if (index >= 400)
                        {
                            break;
                        }
                        else
                        {
                            index++;
                            // dummy[index] = temp;
                            dummy.push_back(temp);
                        }
                        break;
                    }
                    else
                    {
                        // postfix[position++] = temp;
                        postfix.push_back(temp);
                    }
                }
                if (index >= 400)
                {
                    break;
                }
                else
                {
                    index++;
                    dummy.push_back(symbol);
                    // dummy[index] = symbol;
                }
                break;
            default:
                postfix.push_back(symbol);
                // postfix[position++] = symbol;
                break;
            }
            i++;
        }
        while (index >= 0)
        {
            if (index == -1)
            {
                break;
            }
            else
            {
                temp = dummy[index];
                index--;
            }
            // postfix[position++] = temp;
            postfix.push_back(temp);
        }
        cout<<postfix<<endl;
    }
}