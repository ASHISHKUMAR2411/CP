// binary tree is a tree which has atmost 2 children at any stage of his life ,so for that we have to apply different mixed data structure and algorithim we will see one by one as we move forward,
// the children are called either left or right depending on thier behavior and position 
// different part and sources with which the tree are made 
// 1. data source which every stage holds 
// 2.pointer to the next sub left child which make them connected 
// 3. pointer to the next sub right child  which are connected

// tree is a hierarchical data structure 
// terms which are to be known 
// trees have different termology at different stages which has to be keep in mind while traversing through the tree

// the topmost part is called the root as it the one which start the tree and make it startin point and move it further 
// the elements below other elements are called its children .
// the element just above it are called parents
//  element with no child are called leaves
            //     tree
            //     ----
            //     a
            //    /  \
            //   b    c
            //  / \  /  \
            // d   e f   g 
// the above is the structure of the tree and its branches
// why we need trees

// 1. because it provide the need of the hierarchical sysytem we want to maintain 
// 2.binary tree also provides a special feature of moderate searching which is faster than linked list but slower than array ex. Biary search tree  
// 3.tree provides easy insertion and deleltion but it not faster than linked list but way fastre than array
// 4.it can store many element with setting the limit of the upper part as it uses pointer to do that 

// Applications of trees 
// 1.Manipulate hierarchical data
// 2.Make information easy to search 
// 3.used in digital images for special effects
// 4.Manipulate sorted list of data 
// 5.Router Algorithm
// 6.Form a multi stage decision making 


// we define our tree using structure 


// there are some basic properties of binary tree
// 1.maximum number of nodes at any level  l is 2^l ;
// 2.maximum number of nodes at for any height h of the binary tree is 2^h -1
// 3.for n nodes in the tree we can have log2(n+1) minimum height or level are possibles
// 4.the tree with l leaves can have at least log2(l)+1 levels or height
// 5.if tree has either 2 or no children at every node then number of leaves is always one greater than number of nodes with two children .

// then we have complete binary tree in which except last level we have all nodes have 2 children .
//complete binary tree follows the point no 5 in above properties.

// example of binary tree is binary heap.

// Balanced binary tree:  a tree is balance if its height is log(n) where n is the number of nodes .
// balanced binary tree are more good in performance as they take only log(n) times for search , insert , delete .

//example of balanced binary tree, AVL tree is a self balancing tree where it balances it self with respect to left and right , when the difference between the left and right side is more than 1.
// so in avl the difference between the two sides should be atmost one .

//   


// we are staring tree on the next page onwards
// thanks and regards
// Ashish Kumar 


