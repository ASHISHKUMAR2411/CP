// Implementing K stack in a single array 
#include<bits/stdc++.h>
using namespace std;
struct MyStack{
    int *arr, *next, *top, *sz;
    int freetop, k, capacity;
    MyStack(int cap, int kstack){
        this->freetop = 0;
        this->capacity = cap;
        this->k = kstack;
        this->arr = new int[cap];
        this->next = new int[cap];
        this->top = new int[kstack];
        this->sz = new int[kstack];
        for (int i = 0; i < kstack; i++){
            this->top[i] = -1;
            this->sz[i] = 0;
        }
        for(int i = 0; i < cap-1; i++)
        {
            this->next[i] = i + 1;
        }
        this->next[cap - 1] = -1;
    }
    bool isFull(){
        return this->freetop == -1;
    }
    bool isEmpty(int kth){
        return this->top[kth - 1] == -1;
    }
    void push(int x, int kth){ 
        if(isFull()){
            cout << "OverFLow\n";
            return;
        }
        this->sz[kth-1]++;
        int i = this->freetop;
        this->freetop = this->next[i];
        this->next[i] = this->top[i];
        this->top[kth - 1] = i;
        this->arr[i] = x;
    }
    int pop(int kth){
        if(isEmpty(kth)){
            cout << "UnderFlow\n";
            return INT_MIN;
        }
        this->sz[kth - 1]--;
        int i = this->top[kth-1];
        this->top[kth - 1] = this->next[i];
        this->next[i] = this->freetop;
        this->freetop = i;
        return this->arr[i];
    }
    int peek(int kth){
        if (isEmpty(kth))
        {
            cout << "UnderFlow\n";
            return INT_MIN;
        }
        return this->arr[this->top[kth - 1]];
    }
    int size(int kth){
        return this->sz[kth - 1];
    }
    void DisplayStack(int kth)
    {
        if (isEmpty(kth))
        {
            cout << "UnderFlow\n";
            return;
        }
        // well this will change the code then after that we can fetch again
        int i = this->top[kth - 1];
        while (i != -1)
        {
            i = this->next[i];
            this->next[i] = i;
            printf("|%2d|\n", this->arr[i]);
        }
    }
};

int main(){
    srand(time(0));
    int n = 50;
    int k = 3;
    // while(k > n)
    //     n = rand() % 67;
    MyStack s(n, k);
    int p = 25;
    for (int i = 0; i < 10;i++){
        s.push(rand() % 100, 1);
    }
    for (int i = 0; i < 10;i++){
        s.push(rand() % 100, 2);
    }
    for (int i = 0; i < 10;i++){
        s.push(rand() % 100, 3);
    }
    s.DisplayStack(1);
    s.DisplayStack(2);
    s.DisplayStack(3);
    // for(int i = 0; i < p; i++){
    //     int q = rand() % 7 + 1;
    //     while (q>k)
    //     {
    //         q = rand() % 7 + 1;
    //     }

    //     s.push(rand() % 100,q);
    // }
    // for (int i = 0; i < k; i++)
    // {
    //     cout << "\n";
    //     s.DisplayStack(i+1);
    //     cout << "-----\n";
    // }
    return 0;
}