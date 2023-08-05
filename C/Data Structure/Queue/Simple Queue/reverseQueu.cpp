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
    queue<int> q;
    srand(time(0));
    MyStack Stack;
    int n = rand() % 50;
    cout << "Queue size is : ";
    cout << n << "\n";
    for (int i = 0; i < n; i++)
    {
        q.push(rand() % 100);
    }
    cout << "Queue is : \n";
    while(!q.empty()){
        cout << "| " << q.front() << " |\n";
        Stack.push(q.front());
        q.pop();
    }
    // Reversing the queue
    while(!Stack.isEmpty()){
        q.push(Stack.pop());
    }
    cout << "Queue is : \n";
    while(!q.empty()){
        cout << "| " << q.front() << " |\n";
        q.pop();
    }
    return 0;
}
