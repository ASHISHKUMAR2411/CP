#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

struct Queue{
    Node *front, *rear;
    Queue(){
        front = NULL;
        rear = NULL;
    }
    void enqueue(int item){
        Node *temp = new Node();
        temp->data = item;
        temp->next = NULL;
        if(rear == NULL){
            front = temp;
            rear = temp;
        }
        else{
            rear->next = temp;
            rear = temp;
        }
    }
    int dequeue(){
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
    bool isFull(){
        return false;
    }
};

int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    cout<<q.peekFront()<<endl;
    cout<<q.peekRear()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.peekFront()<<endl;
    cout<<q.peekRear()<<endl;
    return 0;
}