#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        this->data = x;
        this->next = NULL;
    }
};

struct MyStack
{
    Node *head;
    int size = 0;
    MyStruct()
    {
        this->head = NULL;
        this->size = 0;
    }
    void push(int x)
    {
        Node *temp = new Node(x);
        temp->next = this->head;
        this->head = temp;
        this->size++;
    }
    int pop()
    {
        if (this->head == NULL)
        {
            cout << "Can't Pop from empty Stack\n";
            return INT_MIN;
        }
        int x = this->head->data;
        Node *temp = this->head;
        this->head = this->head->next;
        delete (temp);
        this->size--;
        return x;
    }
    int Size()
    {
        return this->size;
    }
    bool isEmpty()
    {
        return (this->head == NULL);
    }
    int peek()
    {
        if (this->head == NULL)
        {
            cout << "Stack is Empty\n";
            return INT_MIN;
        }
        return (this->head->data);
    }
    void DisplayStack()
    {
        if (this->head == NULL)
        {
            cout << "Stack is Empty\n";
            return;
        }
        Node *temp = this->head;
        while (temp != NULL)
        {
            printf("| %2d |\n", temp->data);
            temp = temp->next;
        }
        cout << "------" << "\n";
        return;
    }
};

int main()
{
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