# Tree: Postorder Traversal

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Complete the $postOrder$ function in the editor below.  It received $1$ parameter: a pointer to the root of a binary tree. It must print the values in the tree's postorder traversal as a single line of space-separated values.  

**Input Format**

Our test code passes the root node of a binary tree to the $postOrder$ function.

**Constraints**

  $1$ $\leq$Nodes in the tree  $\leq$ $500$

**Output Format**

Print the tree's postorder traversal as a single line of space-separated values.

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-05T14:59:52.658Z  

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


    void postOrder(Node *root) {
        if(root==NULL){
            return ;
        }
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }


```

---

[View on HackerRank](https://www.hackerrank.com/challenges/tree-postorder-traversal/problem)