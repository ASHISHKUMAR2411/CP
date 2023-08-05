// Stack implementation using Array/ Vector
#include<bits/stdc++.h>
using namespace std;
struct MyStack{
    vector<int> Array;
    int size = 0;
    void push(int x){
        this->Array.push_back(x);
        this->size++;
    }
    int pop(){
        if(this->size == 0){
            cout << "Stack is empty\n";
            return INT_MIN;
        }
        int x = this->Array[this->size - 1];
        this->size--;
        this->Array.pop_back();
        return x;
    }
    int peek(){
        if (this->size == 0)
        {
            cout << "Stack is empty\n";
            return INT_MIN;
        }
        return this->Array[this->size - 1];
    }
    void DisplayStack(){
        if (this->size == 0)
        {
            cout << "Stack is empty\n";
            return ;
        }
        for(int i = this->size - 1; i >= 0; i--){
            printf("| %2d |\n", this->Array[i]);
        }
        cout << "------"<< "\n";
        return;
    }
    int Size(){
        return this->size;
    }
    bool isEmpty(){
        return this->size == 0;
    }
};
int main(){
    srand(time(0));
    MyStack Stack;
    int n = rand() % 50;
    cout << "Stack size is : ";
    cout << n << "\n";
    for (int i = 0; i < n; i++)
    {
        Stack.push(rand() % 100);
    }
    cout << "Stack is : \n";
    Stack.DisplayStack();
    cout << endl;
    cout << "Stack size is : " << Stack.Size() << "\n";
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
