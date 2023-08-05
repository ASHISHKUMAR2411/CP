// Implementation Of Two stack in an array 
#include<bits/stdc++.h>
using namespace std;
struct MyStack{
    int *arr;
    int cap, sz1, sz2, top1, top2;
    MyStack(int x){
        this->cap = x;
        this->top2 = this->cap;
        this->top1 = -1;
        this->sz1 = this->sz2 = 0;
        this->arr = new int[x];
    }
    void push1(int x){
        if(this->top1 < this->top2 - 1){
            this->top1++;
            this->sz1++;
            this->arr[this->top1] = x;
        }
        else{
            cout << "OverFlow\n";
        }
    }
    void push2(int x){
        if(this->top1 < this->top2 - 1){
            this->top2--;
            this->sz2++;
            this->arr[this->top2] = x;
        }
        else{
            cout << "OverFlow\n";
        }
    }
    int pop2(){
        if(this->top2 < this->cap){
            int x = this->arr[this->top2];
            this->top2++;
            this->sz2--;
            return x;
        }
        else{
            cout << "UnderFlow\n";
            return INT_MIN;
        }
    }
    int pop1(){
        if(this->top1 >= 0){
            int x = this->arr[this->top1];
            this->top1--;
            this->sz1--;
            return x;
        }
        else{
            cout << "UnderFlow\n";
            return INT_MIN;
        }
    }
    int size1(){
        return this->sz1;
    }
    int size2(){
        return this->sz2;
    }
    int peek1(){
        if(this->sz1 == 0){
            cout << "No element FOund \n";
            return INT_MIN;
        }
        return this->arr[this->top1];
    }
    int peek1(){
        if(this->sz2 == 0){
            cout << "No element FOund \n";
            return INT_MIN;
        }
        return this->arr[this->top2];
    }
}

// Now just implement the main for it.