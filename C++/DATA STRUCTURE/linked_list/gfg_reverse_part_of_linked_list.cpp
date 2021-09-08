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
void quickSort(LinkedList **headRef);
void reverseListTwoPointer(LinkedList **head);
int LengthList(LinkedList *head);
void mergeList();
LinkedList *ReversePart(LinkedList *head, int k);
LinkedList *ReversePartUsingStack(LinkedList *head, int k); // better space complexity .... for larger nodes with small value of k , is k is larger than half the length of the list than normal above function is better
int main()
{

    LinkedList *Head = new LinkedList;
    cout << "enter the first node value : ";
    cin >> Head->data;
    Head->link = NULL;
    while (1)
    {
        cout << "1. Insertion " << endl;
        cout << "2. DisplayList " << endl;
        cout << "3. ReverseList  " << endl;
        cout << "4. LengthOfList " << endl;
        cout << "5. Sorting the List " << endl;
        cout << "6. Merge two Sorted List " << endl;
        cout << "7. Reverse consecutive K parts " << endl;
        cout << "8. Reverse consecutive K parts Using Stack " << endl;
        cout << "9. Exit " << endl;
        cout << "\nEnter the Operation : " << endl;
        int n, k;
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
            quickSort(&Head);
            display(Head);
            break;
        case 6:
            mergeList();
            break;
        case 7:
            cout << "enter the value of K part which you want to swap : ";
            cin >> k;
            Head = ReversePart(Head, k);
            display(Head);
            break;
        case 8:
            cout << "enter the value of K part which you want to swap : ";
            cin >> k;
            Head = ReversePart(Head, k);
            display(Head);
            break;
        case 9:
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
int LengthList(LinkedList *head)
{
    int count = 0;
    while (head)
    {
        count++;
        head = head->link;
    }
    return count;
}
// Returns the last node of the list
LinkedList *getTail(LinkedList *cur)
{
    while (cur != NULL && cur->link != NULL)
        cur = cur->link;
    return cur;
}

// Partitions the list taking the last element as the pivot
LinkedList *partition(LinkedList *head, LinkedList *end, LinkedList **newHead, LinkedList **newEnd)
{
    LinkedList *pivot = end;
    LinkedList *prev = NULL, *cur = head, *tail = pivot;

    // During partition, both the head and end of the list
    // might change which is updated in the newHead and
    // newEnd variables
    while (cur != pivot)
    {
        if (cur->data < pivot->data)
        {
            // First node that has a value less than the
            // pivot - becomes the new head
            if ((*newHead) == NULL)
                (*newHead) = cur;

            prev = cur;
            cur = cur->link;
        }
        else // If cur node is greater than pivot
        {
            // Move cur node to next of tail, and change
            // tail
            if (prev)
                prev->link = cur->link;
            LinkedList *tmp = cur->link;
            cur->link = NULL;
            tail->link = cur;
            tail = cur;
            cur = tmp;
        }
    }

    // If the pivot data is the smallest element in the
    // current list, pivot becomes the head
    if ((*newHead) == NULL)
        (*newHead) = pivot;

    // Update newEnd to the current last node
    (*newEnd) = tail;

    // Return the pivot node
    return pivot;
}

// here the sorting happens exclusive of the end node
LinkedList *quickSortRecur(LinkedList *head, LinkedList *end)
{
    // base condition
    if (!head || head == end)
        return head;

    LinkedList *newHead = NULL, *newEnd = NULL;

    // Partition the list, newHead and newEnd will be
    // updated by the partition function
    LinkedList *pivot = partition(head, end, &newHead, &newEnd);

    // If pivot is the smallest element - no need to recur
    // for the left part.
    if (newHead != pivot)
    {
        // Set the node before the pivot node as NULL
        LinkedList *tmp = newHead;
        while (tmp->link != pivot)
            tmp = tmp->link;
        tmp->link = NULL;

        // Recur for the list before pivot
        newHead = quickSortRecur(newHead, tmp);

        // Change next of last node of the left half to
        // pivot
        tmp = getTail(newHead);
        tmp->link = pivot;
    }

    // Recur for the list after the pivot element
    pivot->link = quickSortRecur(pivot->link, newEnd);

    return newHead;
}

// The main function for quick sort. This is a wrapper over
// recursive function quickSortRecur()
void quickSort(LinkedList **headRef)
{
    (*headRef) = quickSortRecur(*headRef, getTail(*headRef));
    return;
}
void mergeList()
{
    LinkedList *h1 = new LinkedList, *h2 = new LinkedList;
    cout << "enter the first value for first linked list : ";
    cin >> h1->data;
    int n;
    h1->link = NULL;
    while (1)
    {
        cout << "1. for insertion : \n";
        cout << "2. for stop insertion : \n";
        cout << "enter your choice \n ";
        cin >> n;
        switch (n)
        {
        case 1:
            insertion(h1);
            break;
        case 2:
            goto there;
            break;
        default:
            cout << " wrong choice : " << endl;
        }
    }
there:
    cout << "enter the first value for second linked list : ";
    cin >> h2->data;
    h2->link = NULL;
    while (1)
    {
        cout << "1. for insertion : \n";
        cout << "2. for stop insertion : \n";
        cout << "enter your choice \n ";
        cin >> n;
        switch (n)
        {
        case 1:
            insertion(h1);
            break;
        case 2:
            goto the;
            break;
        default:
            cout << " wrong choice : " << endl;
            break;
        }
    }
the:
    quickSort(&h1);
    quickSort(&h2);
    LinkedList *res = NULL, *temp = NULL;
    if (h1 == NULL && h2 == NULL)
        return;
    while (h1 && h2)
    {
        if (h1->data < h2->data)
        {
            temp = h1->link;
            h1->link = res;
            res = h1;
            h1 = temp;
        }
        else
        {
            temp = h2->link;
            h2->link = res;
            res = h2;
            h2 = temp;
        }
    }
    while (h1 != NULL)
    {
        temp = h1->link;
        h1->link = res;
        res = h1;
        h1 = temp;
    }
    while (h2 != NULL)
    {
        temp = h2->link;
        h2->link = res;
        res = h2;
        h2 = temp;
    }
    display(res);
}
LinkedList *ReversePart(LinkedList *head, int k)
{
    if (head == NULL)
        return NULL;
    LinkedList *current = head, *next = NULL, *prev = NULL;
    int count = 0;
    while (current != NULL && count < k)
    {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
        count++;
    }
    if (next != NULL)
        head->link = ReversePart(next, k);
    return prev;
}
LinkedList *ReversePartUsingStack(LinkedList *head, int k)
{
    stack<LinkedList *> myStack;
    LinkedList *curr = head, *prev = NULL;
    while (curr)
    {
        int count = 0;
        while (curr && LengthList(curr) < k)
        {
            myStack.push(curr);
            curr = curr->link;
            count++;
        }
        while (myStack.size() > 0)
        {
            if (prev == NULL)
            {
                prev = myStack.top();
                head = prev;
                myStack.pop();
            }
            else
            {
                prev->link = myStack.top();
                prev = prev->link;
                myStack.pop();
            }
        }
    }
    prev->link = NULL;
    return head;
}