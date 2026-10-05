# Tree: Inorder Traversal

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

In this challenge, you are required to implement inorder traversal of a tree. 

Complete the $inOrder$ function in your editor below, which has $1$ parameter: a pointer to the root of a binary tree. It must print the values in the tree's inorder traversal as a single line of space-separated values.  

**Input Format**

Our hidden tester code passes the root node of a binary tree to your $inOrder* function.

**Constraints**

 $1$ $\leq$ $Nodes$ $in$ $the$ $tree$ $\leq$ $500$

**Output Format**

Print the tree's inorder traversal as a single line of space-separated values.

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-05T15:02:33.714Z  

```cpp


/* you only have to complete the function given below.  
Node is defined as  

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    void inOrder(Node *root) {
        if(root==NULL){
            return ;
        }
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }


```

---

[View on HackerRank](https://www.hackerrank.com/challenges/tree-inorder-traversal/problem)