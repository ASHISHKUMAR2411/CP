#include<bits/stdc++.h>
using namespace std;

struct Deque{
    int *arr;
    int front, cap, size;
    Deque(int c){
        cap = c;
        arr = new int[cap];
        front = 0;
        size = 0 ;
    }
    bool isFull(){
        return size == cap;
    }
    bool isEmpty(){
        return size == 0;
    }
    void Insert_Front(int item){
        if(isFull()){
            cout << "Queue is full" << endl;
            return;
        }
        front = (front - cap + 1)%cap;
        arr[front] = item;
        size++;
    }
    void Insert_Rear(int item){
        if(isFull()){
            cout << "Queue is full" << endl;
            return;
        }
        int rear = (front + size)%cap;
        arr[rear] = item;
        size++;
    }
    int Delete_Front(){
        if(isEmpty()){
            cout << "Queue is empty" << endl;
            return INT_MIN;
        }
        int item = arr[front];
        front = (front + 1)%cap;
        size--;
        return item;
    }
    int Delete_Rear(){
        if(isEmpty()){
            cout << "Queue is empty" << endl;
            return INT_MIN;
        }
        int item = arr[(front + size - 1)%cap];
        size--;
        return item;
    }
    void print(){
        for(int i = 0; i < size; i++){
            cout << arr[(front + i)%cap] << " ";
        }
        cout << endl;
    }
    int peekFront(){
        if(isEmpty()){
            cout << "Queue is empty" << endl;
            return INT_MIN;
        }
        return arr[front];
    }
    int peekRear(){
        if(isEmpty()){
            cout << "Queue is empty" << endl;
            return INT_MIN;
        }
        return arr[(front + size - 1)%cap];
    }
};