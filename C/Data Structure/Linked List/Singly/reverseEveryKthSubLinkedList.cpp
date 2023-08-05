// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
    node(int x)
    {
        data = x;
        next = NULL;
    }
};
!pip install roboflow

from roboflow import Roboflow
rf = Roboflow(api_key="ZTavHQkXLk4uy2wb7KiX")
project = rf.workspace("yognews").project("news_recommend")
dataset = project.version(1).download("coco")
/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element
  Return the node which points to the head of the new LinkedList
  Node is defined as
    struct node
    {
        int data;
        struct node* next;

        node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/
#include <bits/stdc++.h>
class Solution
{
public:
    struct node *reverseSub(struct node *head)
    {
        struct node *current = head;
        struct node *prev = NULL, *next = NULL;

        while (current != NULL)
        {
            // Store next
            next = current->next;
            // Reverse current node's pointer
            current->next = prev;
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
        prev = head;
        while (prev->next != NULL)
        {
            prev = prev->next;
        }
        return prev;
    }

    struct node *reverse(struct node *head, int k)
    {
        // Complete this method
        // base case
        if (!head)
            return NULL;
        struct node *current = head;
        struct node *next = NULL;
        struct node *prev = NULL;
        int count = 0;

        /*reverse first k nodes of the linked list */
        while (current != NULL && count < k)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }

        /* next is now a pointer to (k+1)th node
        Recursively call for the list starting from current.
        And make rest of the list as next of first node */
        if (next != NULL)
            head->next = reverse(next, k);

        /* prev is new head of the input list */
        return prev;
    }
};

// { Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin >> t;

    while (t--)
    {
        struct node *head = NULL;
        struct node *temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int value;
            cin >> value;
            if (i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }

    return (0);
}

// } Driver Code Ends