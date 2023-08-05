#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct CircularQueue
{
    int front, rear, size;
    int capacity;
    vector<int> queue;
    CircularQueue(int cap){
        front = -1;
        rear = -1;
        size = 0;
        capacity = cap;
        queue.resize(cap);
    }
    void enqueue(int item){
        if(size == capacity){
            cout<<"Queue is full"<<endl;
            return;
        }
        if(rear == -1){
            front = 0;
            rear = 0;
        }
        else{
            rear = (rear + 1) % queue.size();
        }
        queue[rear] = item;
        size++;
    }
    int dequeue(){
        if(size == 0){
            cout<<"Queue is empty"<<endl;
            return INT_MIN;
        }
        int item = queue[front];
        if(front == rear){
            front = -1;
            rear = -1;
        }
        else{
            front = (front + 1) % queue.size();
        }
        size--;
        return item;
    }
    int peekFront(){
        if(size == 0){
            cout<<"Queue is empty"<<endl;
            return INT_MIN;
        }
        return queue[front];
    }
    int peekRear(){
        if(size == 0){
            cout<<"Queue is empty"<<endl;
            return INT_MIN;
        }
        return queue[rear];
    }
    bool isEmpty(){
        return size == 0;
    }
    bool isFull(){
        return size == capacity;
    }
};

