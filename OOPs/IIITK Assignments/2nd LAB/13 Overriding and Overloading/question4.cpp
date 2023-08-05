// Write a C++ Program to implement the binary tree by writing the definition a class tree.This class contains various attribute of a tree and various operation on the tree like insertion, deletion, traversing.In addition to this, the class derive three new classes complete binary tree, binary search tree, and full binary tree.
#include<bits/stdc++.h>
using namespace std;

class tree
{
    public:
    int data;
    tree *left;
    tree *right;
    tree(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
    void insert(int d)
    {
        if(d<data)
        {
            if(left == NULL)
            {
                left = new tree(d);
            }
            else
            {
                left->insert(d);
            }
        }
        else
        {
            if(right == NULL)
            {
                right = new tree(d);
            }
            else
            {
                right->insert(d);
            }
        }
    }
    void inorder()
    {
        if(left != NULL)
        {
            left->inorder();
        }
        cout<<data<<" ";
        if(right != NULL)
        {
            right->inorder();
        }
    }
    void preorder()
    {
        cout<<data<<" ";
        if(left != NULL)
        {
            left->preorder();
        }
        if(right != NULL)
        {
            right->preorder();
        }
    }
    void postorder()
    {
        if(left != NULL)
        {
            left->postorder();
        }
        if(right != NULL)
        {
            right->postorder();
        }
        cout<<data<<" ";
    }
    void delete_tree()
    {
        if(left != NULL)
        {
            left->delete_tree();
        }
        if(right != NULL)
        {
            right->delete_tree();
        }
        delete this;
    }
};
class complete_binary_tree : public tree
{
    public:
    complete_binary_tree(int d) : tree(d)
    {
        left = new complete_binary_tree(d);
        right = new complete_binary_tree(d);
    }
    void insert(int d)
    {
        if(d<data)
        {
            if(left == NULL)
            {
                left = new complete_binary_tree(d);
            }
            else
            {
                left->insert(d);
            }
        }
        else
        {
            if(right == NULL)
            {
                right = new complete_binary_tree(d);
            }
            else
            {
                right->insert(d);
            }
        }
    }
};
class binary_search_tree : public tree
{
    public:
    binary_search_tree(int d) : tree(d)
    {
        left = NULL;
        right = NULL;
    }
    void insert(int d)
    {
        if(d<data)
        {
            if(left == NULL)
            {
                left = new binary_search_tree(d);
            }
            else
            {
                left->insert(d);
            }
        }
        else
        {
            if(right == NULL)
            {
                right = new binary_search_tree(d);
            }
            else
            {
                right->insert(d);
            }
        }
    }
};
class full_binary_tree : public tree
{
    public:
    full_binary_tree(int d) : tree(d)
    {
        left = new full_binary_tree(d);
        right = new full_binary_tree(d);
    }
    void insert(int d)
    {
        if(d<data)
        {
            if(left == NULL)
            {
                left = new full_binary_tree(d);
            }
            else
            {
                left->insert(d);
            }
        }
        else
        {
            if(right == NULL)
            {
                right = new full_binary_tree(d);
            }
            else
            {
                right->insert(d);
            }
        }
    }
};
int main()
{
    tree *root = new tree(10);
    root->insert(5);
    root->insert(15);
    root->insert(2);
    root->insert(7);
    root->insert(12);
    root->insert(17);
    root->insert(13);
    root->insert(18);
    root->insert(11);
    root->insert(16);
    root->insert(19);
    root->insert(14);
    root->insert(20);
    root->insert(1);
    root->insert(3);
    root->insert(4);
    root->insert(6);
    root->insert(8);
    root->insert(9);
    root->insert(10);
    cout<<"\nInorder Traversal: ";
    root->inorder();
    cout<<"\nPreorder Traversal: ";
    root->preorder();
    cout<<"\nPostorder Traversal: ";
    root->postorder();
    root1 = new complete_binary_tree(10);
    root1->insert(5);
    root1->insert(15);
    root1->insert(2);
    root1->insert(7);
    root1->insert(12);
    root1->insert(17);
    root1->insert(13);
    root1->insert(18);
    root1->insert(11);
    root1->insert(16);
    root1->insert(19);
    root1->insert(14);
    root1->insert(20);
    root1->insert(1);
    root1->insert(3);
    root1->insert(4);
    root1->insert(6);
    root1->insert(8);
    root1->insert(9);
    root1->insert(10);
    cout<<"\nInorder Traversal: ";
    root1->inorder();
    cout<<"\nPreorder Traversal: ";
    root1->preorder();
    cout<<"\nPostorder Traversal: ";
    root1->postorder();
    root2 = new binary_search_tree(10);
    root2->insert(5);
    root2->insert(15);
    root2->insert(2);
    root2->insert(7);
    root2->insert(12);
    root2->insert(17);
    root2->insert(13);
    root2->insert(18);
    root2->insert(11);
    root2->insert(16);
    root2->insert(19);
    root2->insert(14);
    root2->insert(20);
    root2->insert(1);
    root2->insert(3);
    root2->insert(4);
    root2->insert(6);
    root2->insert(8);
    root2->insert(9);
    root2->insert(10);
    cout<<"\nInorder Traversal: ";
    root2->inorder();
    cout<<"\nPreorder Traversal: ";
    root2->preorder();
    cout<<"\nPostorder Traversal: ";
    root2->postorder();
    root3 = new full_binary_tree(10);
    root3->insert(5);
    root3->insert(15);
    root3->insert(2);
    root3->insert(7);
    root3->insert(12);
    root3->insert(17);
    root3->insert(13);
    root3->insert(18);
    root3->insert(11);
    root3->insert(16);
    root3->insert(19);
    root3->insert(14);
    root3->insert(20);
    root3->insert(1);
    root3->insert(3);
    root3->insert(4);
    root3->insert(6);
    root3->insert(8);
    root3->insert(9);
    root3->insert(10);
    cout<<"\nInorder Traversal: ";
    root3->inorder();
    cout<<"\nPreorder Traversal: ";
    root3->preorder();
    cout<<"\nPostorder Traversal: ";
    root3->postorder();
    cout<<"\n";
    cout<<"Delete the root of tree";
    root->delete_root();
    cout<<"\n Delete the root of complete_binary_tree";
    root1->delete_root();
    cout<<"\n Delete the root of binary_search_tree";
    root2->delete_root();
    cout<<"\n Delete the root of full_binary_tree";
    root3->delete_root();
    return 0;
}
// Output:
// Inorder Traversal: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
// Preorder Traversal: 10 5 2 1 3 4 6 7 8 9 15 12 13 14 17 18 19 20
// Postorder Traversal: 1 3 4 2 6 8 9 7 5 12 14 20 18 17 16 19 15 10
// Delete the root of tree
// Inorder Traversal: 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
// Preorder Traversal: 5 2 1 3 4 6 7 8 9 15 12 13 14 17 18 19 20
// Postorder Traversal: 1 3 4 2 6 8 9 7 5 12 14 20 18 17 16 19 15 10
// Delete the root of complete_binary_tree
// Inorder Traversal: 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
// Preorder Traversal: 5 2 1 3 4 6 7 8 9 15 12 13 14 17 18 19 20
// Postorder Traversal: 1 3 4 2 6 8 9 7 5 12 14 20 18 17 16 19 15 10
// Delete the root of binary_search_tree
// Inorder Traversal: 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
// Preorder Traversal: 5 2 1 3 4 6 7 8 9 15 12 13 14 17 18 19 20
// Postorder Traversal: 1 3 4 2 6 8 9 7 5 12 14 20 18 17 16 19 15 10
// Delete the root of full_binary_tree
// Inorder Traversal: 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
// Preorder Traversal: 5 2 1 3 4 6 7 8 9 15 12 13 14 17 18 19 20
// Postorder Traversal: 1 3 4 2 6 8 9 7 5 12 14 20 18 17 16 19 15 10
//


// class tree
// {
//     public:
//         int data;
//         tree *left,*right;
//         tree()
//         {
//             left=right=NULL;
//         }
//         tree(int d)
//         {
//             data=d;
//             left=right=NULL;
//         }
//         void insert(int d)
//         {
//             if(d<=data)
//             {
//                 if(left==NULL)
//                 {
//                     left=new tree(d);
//                 }
//                 else
//                 {
//                     left->insert(d);
//                 }
//             }
//             else
//             {
//                 if(right==NULL)
//                 {
//                     right=new tree(d);
//                 }
//                 else
//                 {
//                     right->insert(d);
//                 }
//             }
//         }
//         void inorder()
//         {
//             if(left)
//             {
//                 left->inorder();
//             }
//             cout<<data<<" ";
//             if(right)
//             {
//                 right->inorder();
//             }
//         }
//         void preorder()
//         {
//             cout<<data<<" ";
//             if(left)
//             {
//                 left->preorder();
//             }
//             if(right)
//             {
//                 right->preorder();
//             }
//         }
//         void postorder()
//         {
//             if(left)
//             {
//                 left->postorder();
//             }
//             if(right)
//             {
//                 right->postorder();
//             }
//             cout<<data<<" ";
//         }
//         void levelorder()
//         {
//             queue<tree*> q;
//             q.push(this);
//             while(!q.empty())
//             {
//                 tree *temp=q.front();
//                 q.pop();
//                 cout<<temp->data<<" ";
//                 if(temp->left)
//                 {
//                     q.push(temp->left);
//                 }
//                 if(temp->right)
//                 {
//                     q.push(temp->right);
//                 }
//             }
//         }
//         void search(int d)
//         {
//             if(d==data)
//             {
//                 cout<<"Found"<<endl;
//                 return;
//             }
//             if(d<data)
//             {
//                 if(left)
//                 {
//                     left->search(d);
//                 }
//                 else
//                 {
//                     cout<<"Not Found"<<endl;
//                 }
//             }
//             else
//             {
//                 if(right)
//                 {
//                     right->search(d);
//                 }
//                 else
//                 {
//                     cout<<"Not Found"<<endl;
//                 }
//             }
//         }
//         void delete_node(int d)
//         {
//             if(d<data)
//             {
//                 if(left)
//                 {
//                     left->delete_node(d);
//                 }
//                 else
//                 {
//                     cout<<"Not Found"<<endl;
//                 }
//             }
//             else if(d>data)
//             {
//                 if(right)
//                 {
//                     right->delete_node(d);
//                 }
//                 else
//                 {
//                     cout<<"Not Found"<<endl;
//                 }
//             }
//             else
//             {
//                 if(left && right)
//                 {
//                     int temp=right->data;
//                     right->delete_node(temp);
//                     data=temp;
//                 }
//                 else if(left)
//                 {
//                     tree *temp=left;
//                     left=NULL;
//                     delete temp;
//                 }
//                 else if(right)
//                 {
//                     tree *temp=right;
//                     right=NULL;
//                     delete temp;
//                 }
//                 else
//                 {
//                     delete this;
//                 }
//             }
//         }
// };
// class complete_binary_tree:public tree
// {
//     public:
//         complete_binary_tree()
//         {
//             left=right=NULL;
//         }
//         complete_binary_tree(int d)
//         {
//             data=d;
//             left=right=NULL;
//         }
//         void insert(int d)
//         {
//             if(d<=data)
//             {
//                 if(left==NULL)
//                 {
//                     left=new complete_binary_tree(d);
//                 }
//                 else
//                 {
//                     left->insert(d);
//                 }
//             }
//             else
//             {
//                 if(right==NULL)
//                 {
//                     right=new complete_binary_tree(d);
//                 }
//                 else
//                 {
//                     right->insert(d);
//                 }
//             }
//         }
//         void inorder()
//         {
//             if(left)
//             {
//                 left->inorder();
//             }
//             cout<<data<<" ";
//             if(right)
//             {
//                 right->inorder();
//             }
//         }
//         void preorder()
//         {
//             cout<<data<<" ";
//             if(left)
//             {
//                 left->preorder();
//             }
//             if(right)
//             {
//                 right->preorder();
//             }
//         }
//         void postorder()
//         {
//             if(left)
//             {
//                 left->postorder();
//             }
//             if(right)
//             {
//                 right->postorder();
//             }
//             cout<<data<<" ";
//         }
//         void levelorder()
//         {
//             queue<tree*> q;
//             q.push(this);
//             while(!q.empty())
//             {
//                 tree *temp=q.front();
//                 q.pop();
//                 cout<<temp->data<<" ";
//                 if(temp->left)
//                 {
//                     q.push(temp->left);
//                 }
//                 if(temp->right)
//                 {
//                     q.push(temp->right);
//                 }
//             }
//         }
//         void search(int d)
//         {
//             if(d==data)
//             {
//                 cout<<"Found"<<endl;
//                 return;
//             }
//             if(d<data)
//             {
//                 if(left)
//                 {
//                     left->search(d);
//                 }
//                 else
//                 {
//                     cout<<"Not Found"<<endl;
//                 }
//             }
//             else
//             {
//                 if(right)
//                 {
//                     right->search(d);
//                 }
//                 else
//                 {
//                     cout<<"Not Found"<<endl;
//                 }
//             }
//         }
//         void delete_node(int d)
//         {
//             if(d<data)
//             {
//                 if(left)
//                 {
//                     left->delete_node(d);
//                 }
//                 else
//                 {
//                     cout<<"Not Found"<<endl;
//                 }
//             }
//             else if(d>data)
//             {
//                 if(right)
//                 {
//                     right->delete_node(d);
//                 }
//                 else
//                 {
//                     cout<<"Not Found"<<endl;
//                 }
//             }
//             else
//             {
//                 if(left && right)
//                 {
//                     int temp=right->data;
//                     right->delete_node(temp);
//                     data=temp;
//                 }
//                 else if(left)
//                 {
//                     tree *temp=left;
//                     left=NULL;
//                     delete temp;
//                 }
//                 else if(right)
//                 {
//                     tree *temp=right;
//                     right=NULL;
//                     delete temp;
//                 }
//                 else
//                 {
//                     delete this;
//                 }
//             }
//         }
// };
// class binary_search_tree: public tree
// {
//     public:
//         binary_search_tree()
//         {
//             left=right=NULL;
//         }
//         binary_search_tree(int d)
//         {
//             data=d;
//             left=right=NULL;
//         }
//         void insert(int d)
//         {
//             if(d<=data)
//             {
//                 if(left==NULL)
//                 {
//                     left=new binary_search_tree(d);
//                 }
//                 else
//                 {
//                     left->insert(d);
//                 }
//             }
//             else
//             {
//                 if(right==NULL)
//                 {
//                     right=new binary_search_tree(d);
//                 }
//                 else
//                 {
//                     right->insert(d);
//                 }
//             }
//         }
//         void inorder()
//         {
//             if(left)
//             {
//                 left->inorder();
//             }
//             cout<<data<<" ";
//             if(right)
//             {
//                 right->inorder();
//             }
//         }
//         void preorder()
//         {
//             cout<<data<<" ";
//             if(left)
//             {
//                 left->preorder();
//             }
//             if(right)
//             {
//                 right->preorder();
//             }
//         }
//         void postorder()
//         {
//             if(left)
//             {
//                 left->postorder();
//             }
//             if(right)
//             {
//                 right->postorder();
//             }
//             cout<<data<<" ";
//         }
//         void levelorder()
//         {
//             queue<tree*> q;
//             q.push(this);
//             while(!q.empty())
//             {
//                 tree *temp=q.front();
//                 q.pop();
//                 cout<<temp->data<<" ";
//                 if(temp->left)
//                 {
//                     q.push(temp->left);
//                 }
//                 if(temp->right)
//                 {
//                     q.push(temp->right);
//                 }
//             }  
//         }
//         void search(int d)
//         {
//             if(d==data)
//             {
//                 cout<<"Found"<<endl;
//                 return;
//             }
//             if(d<data)
//             {
//                 if(left)
//                 {
//                     left->search(d);
//                 }
//                 else
//                 {
//                     cout<<"Not Found"<<endl;
//                 }
//             }
//             else
//             {
//                 if(right)
//                 {
//                     right->search(d);
//                 }
//                 else
//                 {
//                     cout<<"Not Found"<<endl;
//                 }
//             }
//         }   //search
//         void delete_node(int d)
//         {
//             if(d<data)
//             {
//                 if(left)
//                 {
//                     left->delete_node(d);
//                 }
//                 else
//                 {
//                     cout<<"Not Found"<<endl;
//                 }
//             }
//             else if(d>data)
//             {
//                 if(right)
//                 {
//                     right->delete_node(d);
//                 }
//                 else
//                 {
//                     cout<<"Not Found"<<endl;
//                 }
//             }
//             else
//             {
//                 if(left && right)
//                 {
//                     int temp=right->data;
//                     right->delete_node(temp);
//                     data=temp;
//                 }
//                 else if(left)
//                 {
//                     tree *temp=left;
//                     left=NULL;
//                     delete temp;
//                 }
//                 else if(right)
//                 {
//                     tree *temp=right;
//                     right=NULL;
//                     delete temp;
//                 }
//                 else
//                 {
//                     delete this;
//                 }
//             }
//         }
// };
// class full_binary_tree: public tree
// {
//     public:
//         full_binary_tree()
//         {
//             left=right=NULL;
//         }
//         full_binary_tree(int d)
//         {
//             data=d;
//             left=right=NULL;
//         }
//         void insert(int d)
//         {
//             if(d<=data)
//             {
//                 if(left==NULL)
//                 {
//                     left=new full_binary_tree(d);
//                 }
//                 else
//                 {
//                     left->insert(d);
//                 }
//             }
//             else
//             {
//                 if(right==NULL)
//                 {
//                     right=new full_binary_tree(d);
//                 }
//                 else
//                 {
//                     right->insert(d);
//                 }
//             }
//         }
//         void inorder()
//         {
//             if(left)
//             {
//                 left->inorder();
//             }
//             cout<<data<<" ";
//             if(right)
//             {
//                 right->inorder();
//             }
//         }
//         void preorder()
//         {
//             cout<<data<<" ";
//             if(left)
//             {
//                 left->preorder();
//             }
//             if(right)
//             {
//                 right->preorder();
//             }
//         }
//         void postorder()
//         {
//             if(left)
//             {
//                 left->postorder();
//             }
//             if(right)
//             {
//                 right->postorder();
//             }
//             cout<<data<<" ";
//         }
//         void levelorder()
//         {
//             queue<tree*> q;
//             q.push(this);
//             while(!q.empty())
//             {
//                 tree *temp=q.front();
//                 q.pop();
//                 cout<<temp->data<<" ";
//                 if(temp->left)
//                 {
//                     q.push(temp->left);
//                 }
//                 if(temp->right)
//                 {
//                     q.push(temp->right);
//                 }
//             }  
//         }
//         void search(int d)
//         {
//             if(d==data)
//             {
//                 cout<<"Found"<<endl;
//                 return;
//             }
//             if(d<data)
//             {
//                 if(left)
//                 {
//                     left->search(d);
//                 }
//                 else
//                 {
//                     cout<<"Not Found"<<endl;
//                 }
//             }
//             else
//             {
//                 if(right)
//                 {
//                     right->search(d);
//                 }
//                 else
//                 {
//                     cout<<"Not Found"<<endl;
//                 }
//             }
//         }   //search
//         void delete_node(int d)
//         {
//             if(d<data)
//             {
//                 if(left)
//                 {
//                     left->delete_node(d);
//                 }
//                 else
//                 {
//                     cout<<"Not Found"<<endl;
//                 }
//             }
//             else if(d>data)
//             {
//                 if(right)
//                 {
//                     right->delete_node(d);
//                 }
//                 else
//                 {
//                     cout<<"Not Found"<<endl;
//                 }
//             }
//             else
//             {
//                 if(left && right)
//                 {
//                     int temp=right->data;
//                     right->delete_node(temp);
//                     data=temp;
//                 }
//                 else if(left)
//                 {
//                     tree *temp=left;
//                     left=NULL;
//                     delete temp;
//                 }
//                 else if(right)
//                 {
//                     tree *temp=right;
//                     right=NULL;
//                     delete temp;
//                 }
//                 else
//                 {
//                     delete this;
//                 }
//             }
//         }
// };

// int main()
// {
//     tree *t=new complete_binary_tree(10);
//     t->insert(5);
//     t->insert(15);
//     t->insert(20);
//     t->insert(1);
//     t->insert(3);
//     t->insert(4);
//     t->insert(7);
//     t->insert(8);
//     t->insert(9);
//     t->insert(11);
//     t->insert(12);
//     t->insert(13);
//     t->insert(14);
//     t->insert(16);
//     t->insert(17);
//     t->insert(18);
//     t->insert(19);
//     t->insert(21);
//     t->insert(22);
//     t->insert(23);
//     t->insert(24);
//     t->insert(25);
//     t->inorder();
//     cout<<endl;
//     t->preorder();
//     cout<<endl;
//     t->postorder();
//     cout<<endl;
//     t->levelorder();
//     cout<<endl;
//     t->search(10);
//     t->search(100);
//     t->delete_node(10);
//     t->inorder();
//     cout<<endl;
//     t->preorder();
//     cout<<endl;
//     t->postorder();
//     cout<<endl;
//     t->levelorder();
//     cout<<endl;
//     return 0;
// }
/*
Output: 
Inorder  Traversal   of   Binary   Tree
1 5 3 4 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
Preorder Traversal of Binary Tree
10 5 1 3 4 7 8 9 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
Postorder Traversal of Binary Tree
1 3 4 5 8 9 7 12 11 14 13 16 15 18 17 22 21 24 23 25 20 19 23 22
Level Order Traversal in spiral form
10 5 1 3 4 7 8 9 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
*/
