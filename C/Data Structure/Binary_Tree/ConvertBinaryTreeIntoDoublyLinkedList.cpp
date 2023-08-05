#include<bits/stdc++.h>
using namespace std;

struct Tree{
    int data;
    Tree *left, *right;
    Tree(int data){
        this->data = data;
        this->left = NULL;
        this->rigth = NULL;
    }
};
