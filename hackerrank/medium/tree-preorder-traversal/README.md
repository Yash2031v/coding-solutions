# Tree: Preorder Traversal

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Complete the $preOrder$ function in the editor below, which has $1$ parameter: a pointer to the root of a binary tree. It must print the values in the tree's preorder traversal as a single line of space-separated values.  


**Input Format**

Our test code passes the root node of a binary tree to the *preOrder* function.

**Constraints**

  $1 \leq$ Nodes in the tree  $\leq 500 $

**Output Format**

Print the tree's preorder traversal as a single line of space-separated values.

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-12T15:58:12.602Z  

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

    void preOrder(Node *root) {
        if(root == NULL){
            return ;
        }
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);

    }


```

---

[View on HackerRank](https://www.hackerrank.com/challenges/tree-preorder-traversal/problem)