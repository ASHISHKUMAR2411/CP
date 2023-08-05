#include<bits/stdc++.h>
using namespace std;

struct Stack{
    queue<int> q1, q2;
    bool isEmpty(){
        return q1.empty();
    }
    int top(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return INT_MIN;
        }
        return q1.front();
    }
    int pop(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return INT_MIN;
        }
        return q1.front();
    }
    void push(int item){
        q2.push(item);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
};

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;
    if(s.isEmpty()){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<s.top()<<endl;
    }
    return 0;
}