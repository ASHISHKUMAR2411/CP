#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

void inOrderTraversal(Node *root)
{
    if (root == NULL)
        return;
    inOrderTraversal(root->left);
    cout << root->key << " ";
    inOrderTraversal(root->right);
}

void preOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->key << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node *root)
{
    if (root == NULL)
        return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->key << " ";
}

int heightTree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return max(heightTree(root->left), heightTree(root->right)) + 1;
}

void PrintKthDistanceNodes(Node *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    k--;
    if (k == 0)
    {
        cout << root->key << " ";
    }
    PrintKthDistanceNodes(root->left, k);
    PrintKthDistanceNodes(root->right, k);
}

// naive approach to find the level order traversal O(height * n node)
void PrintLevelOrderTraversal(Node *root)
{
    int k = heightTree(root);
    for (int i = 1; i <= k; i++)
    {
        PrintKthDistanceNodes(root, i);
        cout << endl;
    }
}

// using queue data structure to print the level order traversal
// width of perfect binary tree is number of nodes / 2 + 1;
// this take O(nodes) time and O(nodes) auxiliary space
void PrintLevelOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (q.empty() == false)
    {
        Node *curr = q.front();
        q.pop();
        cout << curr->key << " ";
        if (curr->left != NULL)
        {
            q.push(curr->left);
        }
        if (curr->right != NULL)
        {
            q.push(curr->right);
        }
    }
}

// as in above we can't determine levels so in this we will have proper level prints
void PrintLevelOrderImproved(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (q.size() > 1 )
    {
        Node *curr = q.front();
        q.pop();
        if (curr == NULL)
        {
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << curr->key << " ";
        if (curr->left != NULL)
        {
            q.push(curr->left);
        }
        if (curr->right != NULL)
        {
            q.push(curr->right);
        }
    }
}

void PrintLevelOrderImproved2(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (q.empty() ==  false)
    {
        int count = q.size();
        for (int i = 0; i < count; i++){
            Node *curr = q.front();
            q.pop();
            cout << curr->key << " ";
            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
        cout << endl;
    }
}

// to find the size of the tree i.e number of nodes
int sizeOfTree(Node *root){
    if(root == NULL){
        return 0;
    }
    return 1 + sizeOfTree(root->left) + sizeOfTree(root->right);
}

// TO find the maximum of the tree
int maximumTree(Node *root){
    if(root == NULL){
        return INT_MIN;
    }
    return max(root->key, max(maximumTree(root->left), maximumTree(root->right)));
}

// Print the left view of the tree.
void LeftViewRecursion(Node *root , int level){
    static int maxlevel = 0;
    if(root == NULL){
        return;
    }
    if(maxlevel < level){
        cout << root->key << endl;
        maxlevel = level;
    }
    LeftViewRecursion(root->left, level + 1);
    LeftViewRecursion(root->right, level + 1);
}

void LeftViewIterative(Node *root){
    if(root == NULL){
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (q.empty() == false){
        int count = q.size();
        for (int i = 0; i < count; i++){
            Node *curr = q.front();
            q.pop();
            if(i == 0){
                cout << curr->key << endl;
            }
            if(curr->left !=NULL){
                q.push(curr->left);
            }
            if(curr->right != NULL){
                q.push(curr->right);
            }
        }
    }
}

// Find whether tree is balanced  naive Approach is O(n*n)
bool isBalancedTree(Node *root){
    if(root == NULL){
        return true;
    }
    int left = heightTree(root->left);
    int right = heightTree(root->right);
    return (abs(left - right) < 2 && isBalancedTree(root->left) && isBalancedTree(root->right));
}

// find whether the tree is balanced or not improved
int isBalancedTreeImproved(Node *root){
    if(root == NULL){
        return 0;
    }
    int left = isBalancedTreeImproved(root->left);
    if(left == -1){
        return -1;
    }
    int right = isBalancedTreeImproved(root->right);
    if(right == -1){
        return -1;
    }
    if(abs(right - left) > 1)
        return -1;
    else return max(right, left) + 1;
}

int maximumWidth(Node *root){
    if(root == NULL){
        return 0;
    }
    queue<Node *> q;
    q.push(root);
    int res = 1;
    while(q.empty() == false){
        int count = q.size();
        res = max(res, count);
        for (int i = 0; i < count ; i++){
            Node *curr = q.front();
            q.pop();
            if(curr->left != NULL){
                q.push(curr->left);
            }
            if(curr->right !=NULL){
                q.push(curr->right);
            }
        }
    }
    return res;
}

bool ChildrenSumProperty(Node *root){
    if(root == NULL){
        return true;
    }
    if(root->left == NULL && root->right == NULL){
        return true;
    }
    int sum = 0;
    if(root->left != NULL){
        sum += root->left->key;
    }
    if(root->right != NULL){
        sum += root->right->key;
    }
    return (root->key == sum && ChildrenSumProperty(root->left) && ChildrenSumProperty(root->right));
}


Node *DoubleLinkedList(Node *root){
    static Node *prev = NULL;
    if (root == NULL)
        return root;
    Node *head = DoubleLinkedList(root->left);
    if(prev == NULL){
        head = root;
    }
    else{
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    DoubleLinkedList(root->right);
    return head;
}

Node *DoubleLinkedList2(Node *root){
    static Node *prev = NULL, *head = NULL;
    if(root == NULL){
        return root;
    }
    DoubleLinkedList2(root->left);
    if(prev == NULL){
        head = root;
    } 
    else{
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    DoubleLinkedList2(root->right);
    return head;
}

void DisplayDoubleLinkedList(Node *root){
    if(root == NULL){
        return;
    }
    else{
        cout << root->key << " ";
        DisplayDoubleLinkedList(root->right);
    }
}

// to find the tree using inorder and preorder
Node *ConstructTree(vector<int> &inorder, vector<int> &preorder, int start, int end){
    static int prevIndex = 0;
    if(start > end){
        return NULL;
    }
    Node *root = new Node(preorder[prevIndex++]);
    int index;
    for (int i = start; i <= end; i++){
        if(inorder[i] == root->key){
            index = i;
            break;
        }
    }
    root->left = ConstructTree(inorder, preorder, start, index - 1);
    root->right = ConstructTree(inorder, preorder, index + 1, end);
    return root;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);
    root->right->left->left = new Node(12);
    root->right->left->right = new Node(13);
    root->right->right->left = new Node(14);
    root->right->right->right = new Node(15);
    inOrderTraversal(root);
    cout << endl;
    preOrderTraversal(root);
    cout << endl;
    postOrderTraversal(root);
    cout << endl;
    cout << heightTree(root) << endl;
    PrintKthDistanceNodes(root, 4);
    cout << endl;
    PrintLevelOrderTraversal(root);
    cout << endl;
    PrintLevelOrder(root);
    cout << endl;
    PrintLevelOrderImproved(root);
    cout << endl;
    PrintLevelOrderImproved2(root);
    cout << endl;
    sizeOfTree(root);
    cout << endl;
    maximumTree(root);
    cout << endl;
    LeftViewRecursion(root, 1);
    cout << endl;
    LeftViewIterative(root);
    cout << endl;
    if(isBalancedTree(root))
        cout << "tree is balanced "<< endl;
    else
        cout <<" tree is not balanced" << endl;
    if (isBalancedTreeImproved(root) == -1){
        cout << "tree is not balanced" << endl;
    }
    else
        cout << " tree is balanced" << endl;
    cout << maximumWidth(root) << " is the maximum width of the tree" << endl;
    Node *head = DoubleLinkedList2(root);
    DisplayDoubleLinkedList(head);
    return 0;
}