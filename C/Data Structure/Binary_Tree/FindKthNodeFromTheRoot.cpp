#include<bits/stdc++.h>
using namespace std;

struct Tree{
    int data;
    Tree *left, *right;
    Tree(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void PrintKthNodeFromRoot(Tree *root, int k){
    if(root == NULL){
        return;
    }
    if(k == 0){
        cout << root->data << " ";
    }
    else{
        PrintKthNodeFromRoot(root->left, k - 1);
        PrintKthNodeFromRoot(root->right, k - 1);
    }
}

int main(){
    Tree *root = new Tree(5);
    root->left = new Tree(4);
    root->right = new Tree(3);
    root->left->left = new Tree(2);
    root->right->left = new Tree(1);
    PrintKthNodeFromRoot(root, 1);
}