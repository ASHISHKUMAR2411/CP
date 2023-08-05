#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
};

struct Deque{
    Node *front, *rear;
    Deque(){
        front = NULL;
        rear = NULL;
    }
    void enqueueFront(int item){
        Node *temp = new Node();
        temp->data = item;
        temp->next = NULL;
        temp->prev = NULL;
        if(front == NULL){
            front = temp;
            rear = temp;
        }
        else{
            temp->next = front;
            front->prev = temp;
            front = temp;
        }
    }
    void enqueueRear(int item){
        Node *temp = new Node();
        temp->data = item;
        temp->next = NULL;
        temp->prev = NULL;
        if(rear == NULL){
            front = temp;
            rear = temp;
        }
        else{
            rear->next = temp;
            temp->prev = rear;
            rear = temp;
        }
    }
    int dequeueFront(){
        if(front == NULL){
            cout<<"Queue is empty"<<endl;
            return INT_MIN;
        }
        int item = front->data;
        if(front == rear){
            front = NULL;
            rear = NULL;
        }
        else{
            front = front->next;
            front->prev = NULL;
        }
        return item;
    }
    int dequeueRear(){
        if(rear == NULL){
            cout<<"Queue is empty"<<endl;
            return INT_MIN;
        }
        int item = rear->data;
        if(front == rear){
            front = NULL;
            rear = NULL;
        }
        else{
            rear = rear->prev;
            rear->next = NULL;
        }
        return item;
    }
    int peekFront(){
        if(front == NULL){
            cout<<"Queue is empty"<<endl;
            return INT_MIN;
        }
        return front->data;
    }
    int peekRear(){
        if(rear == NULL){
            cout<<"Queue is empty"<<endl;
            return INT_MIN;
        }
        return rear->data;
    }
    bool isEmpty(){
        return front == NULL;
    }
};

int main(){
    Deque d;
    d.enqueueFront(10);
    d.enqueueFront(20);
    d.enqueueFront(30);
    d.enqueueFront(40);
    d.enqueueFront(50);
    d.enqueueFront(60);
    d.enqueueFront(70);
    d.enqueueFront(80);
    d.enqueueFront(90);
    d.enqueueFront(100);

    cout<<d.peekFront()<<endl;
    cout<<d.peekRear()<<endl;
    cout<<d.dequeueFront()<<endl;
    cout<<d.dequeueRear()<<endl;
    cout<<d.peekFront()<<endl;
    cout<<d.peekRear()<<endl;
    cout<<d.dequeueFront()<<endl;
    cout<<d.dequeueRear()<<endl;
    cout<<d.peekFront()<<endl;
    cout<<d.peekRear()<<endl;
    cout<<d.dequeueFront()<<endl;
    cout<<d.dequeueRear()<<endl;
    cout<<d.peekFront()<<endl;

    return 0;
}

