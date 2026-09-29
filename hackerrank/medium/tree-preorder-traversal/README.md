# Tree: Preorder Traversal

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Complete the function in the editor below, which has parameter: a pointer to the root of a binary tree. It must print the values in the tree's preorder traversal as a single line of space-separated values.

 **Input Format** 

Our test code passes the root node of a binary tree to the  *preOrder*  function.

 **Constraints** 

Nodes in the tree

 **Output Format** 

Print the tree's preorder traversal as a single line of space-separated values.

 **Sample Input** 

```
     1
      \
       2
        \
         5
        /  \
       3    6
        \
         4  

```

 **Sample Output** 

```
1 2 5 3 4 6 

```

 **Explanation** 

The preorder traversal of the binary tree is printed.

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-29T06:51:37.295Z  

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
        if(root!=NULL){
            std::cout<<root->data<<" ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }


```

---

[View on HackerRank](https://www.hackerrank.com/challenges/tree-preorder-traversal/problem)