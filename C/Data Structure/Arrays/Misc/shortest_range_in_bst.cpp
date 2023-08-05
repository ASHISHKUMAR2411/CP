// Given a BST(Binary Search Tree), find the shortest range [x, y], such that, at least one node of every level of the BST lies in the range.If there are multiple ranges with the same gap(i.e.(y - x)) return the range with the smallest x.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
    Node(int Value) {
        data = Value;
        left = right = NULL;
    }
};

// Function to build tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;
    // creating vector of strings from input
    // string after splitting by space
    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);
    Node *root = new Node(stoi(ip[0]));
    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);
    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();
        // Get the current node's value from the string
        string currVal = ip[i];
        // if the left child is not null
        if(currVal != "N") {
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
            // Push it to the queue
            queue.push(currNode->left);
        }
        // for the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
        // if the right child is not null
        if(currVal != "N") {
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}

class Solution {
    public:
        pair<int,int> shortestRange

int main(){
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution obj;
        pair<int, int> ans = obj.shortestRange(root);
        cout << ans.first << " " << ans.second << endl;
    }
    return 0;
}


