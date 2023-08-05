#include <bits/stdc++.h>
using namespace std;
// void print(stack<int> s)
// {
//     while (s.empty())
//     {
//         cout << s.top() << " ";
//         s.pop();
//     }
// }
int main()
{
    srand(time(0));
    stack<int> Stack, p;
    int n = rand() % 50;
    cout << "Stack size is : ";
    cout << n << "\n";
    for (int i = 0; i < n; i++)
    {
        Stack.push(rand() % 100);
    }
    cout << "Stack is : \n";
    p = Stack;
    while(p.empty()==false){
        print("| %2d |\n", p.top());
        p.pop();
    }
    cout << "------\n";
    cout << "Stack size is : " << Stack.size() << "\n";
    int m = rand() % 10;
    cout << "Number of item pop is : " << m << "\n";
    cout << "Item pop out is : ";
    for (int i = 0; i < m; i++)
    {
        cout << Stack.pop() << " ";
    }
    cout << endl;
    cout << "Stack is : \n";
    Stack.DisplayStack();
    cout << endl;
    cout << "Stack size is : " << Stack.Size() << "\n";
    cout << "Stack top element is : " << Stack.peek() << "\n";
    if (Stack.isEmpty())
    {
        cout << "Stack is empty\n";
    }
    else
        cout << "Stack is not empty\n";
    return 0;
}