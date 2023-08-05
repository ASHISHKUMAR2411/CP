#include <bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define ulli unsigned long long int
#define endl '\n'
#define vi vector<int>
#define pi pair<int, int>
#define vii vector<pi>
#define f(i, m) for (int i = 0; i < m; i++)
#define fi(i, m) for (int i = 1; i <= m; i++)
#define fir(i, n, m) for (int i = n; i <= m; i++)
using namespace std;
typedef uintptr_t ut;
struct LinkedList
{
    int data;
    LinkedList *link;
};
LinkedList *reverseList(LinkedList *head)
{
    LinkedList *curr = head, *prev = nullptr;
    while (curr)
    {
        head = head->link;
        curr->link = prev;
        prev = curr;
        curr = head;
    }
    return prev;
}
void insertion(LinkedList *head);
void display(LinkedList *head);
void reverseListTwoPointer(LinkedList **head);
void LengthList(LinkedList *head);
int main()
{
    cout << "1. Insertion : " << endl;
    cout << "2. DisplayList : " << endl;
    cout << "3. ReverseList : " << endl;
    cout << "4. LengthOfList : " << endl;
    cout << "5. Exit : " << endl;
    LinkedList *Head = new LinkedList;
    cout << "enter the first node value : ";
    cin >> Head->data;
    Head->link = NULL;
    while (1)
    {
        cout << "\nEnter the Operation You Want to implement in the LinkedList " << endl;
        int n;
        cin >> n;
        switch (n)
        {
        case 1:
            insertion(Head);
            break;
        case 2:
            display(Head);
            break;
        case 3:
            reverseListTwoPointer(&Head);
            break;
        case 4:
            LengthList(Head);
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << " wrong choice : ";
        }
    }
}
void insertion(LinkedList *head)
{
    if (head == NULL)
    {
        LinkedList *temp = new LinkedList;
        cout << "enter the data : ";
        cin >> temp->data;
        temp->link = NULL;
        head = temp;
        return;
    }
    LinkedList *ptr = head;
    while (head)
    {
        ptr = head;
        head = head->link;
    }
    LinkedList *temp = new LinkedList;
    cout << "enter the data : ";
    cin >> temp->data;
    temp->link = NULL;
    ptr->link = temp;
}
void display(LinkedList *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->link;
    }
    cout << endl;
}
void reverseListTwoPointer(LinkedList **head)
{
    LinkedList *prev = NULL;
    LinkedList *current = *head;
    while (current)
    {
        current = (LinkedList *)((ut)prev ^ (ut)current ^ (ut)(current->link) ^ (ut)(current->link = prev) ^ (ut)(prev = current));
    }
    *head = prev;
}
void LengthList(LinkedList *head)
{
    int count = 0;
    while (head)
    {
        count++;
        head = head->link;
    }
    cout << "the Length is : " << count;
}