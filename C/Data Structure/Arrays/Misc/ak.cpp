// You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n. You are also given an integer startValue representing the value of the start node s, and a different integer destValue representing the value of the destination node t.Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such path as a string consisting of only the uppercase letters 'L', 'R', and 'U'. Each letter indicates a specific direction:
// 'L' means to go from a node to its left child node.
// 'R' means to go from a node to its right child node.
// 'U' means to go from a node to its parent node.
// Return the step-by-step directions of the shortest path from node s to node t.

// Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
// Output: "UURL"
// Explanation: The shortest path is: 3 → 1 → 5 → 2 → 6.

#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

string getDirections(TreeNode *root, int startValue, int destValue){
    if(!root) return "";
    if(root->val == startValue) return getDirections(root->left, startValue, destValue);
    if(root->val == destValue) return "U" + getDirections(root->left, startValue, destValue);
    if(root->val > startValue && root->val < destValue) return "L" + getDirections(root->left, startValue, destValue);
    if(root->val < startValue && root->val > destValue) return "R" + getDirections(root->right, startValue, destValue);
    return "";
}

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(6);
    root->right->right = new TreeNode(4);
    string directions = getDirections(root, 3, 6);
    cout << directions << endl;
    return 0;
}
