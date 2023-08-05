#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

struct Queue{
    int size, front, rear;
    vector<int> queue;
    Queue(){
        size = 0;
        front = -1;
        rear = -1;
        queue.reserve((int)1e6);
    }
    void enqueue(int item){
        if(isFull()){
            cout<<"Queue is full"<<endl;
            return;
        }
        if(rear == -1){
            front = 0;
            rear = 0;
        }
        else{
            rear++;
        }
        queue.push_back(item);
        size++;
    }
    int dequeue(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return INT_MIN;
        }
        int item = queue[front];
        if(front == rear){
            front = -1;
            rear = -1;
        }
        size--;
        queue.erase(queue.begin());
        return item;
    }
    int peekFront(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return INT_MIN;
        }
        return queue.front();
    }
    int peekRear(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return INT_MIN;
        }
        return queue.back();
    }
    bool isEmpty(){
        return size == 0;
    }
    bool isFull(){
        return size == queue.capacity();
    }
};

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    cout<<q.peekFront()<<endl;
    cout<<q.peekRear()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;

    return 0;

}