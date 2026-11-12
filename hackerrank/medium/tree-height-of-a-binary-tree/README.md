# Tree: Height of a Binary Tree

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

The height of a binary tree is the number of edges between the tree's root and its furthest leaf.  For example, the following binary tree is of height $2$:

![image](https://s3.amazonaws.com/hr-assets/0/1527626183-88c8070977-isitBSTSample0.png)  
**Function Description**

Complete the *getHeight* or *height* function in the editor.  It must return the height of a binary tree as an integer.

getHeight or height has the following parameter(s):

- *root*: a reference to the root of a binary tree.    

**Note** -The Height of binary tree with single node is taken as zero.  

**Input Format**

The first line contains an integer $n$, the number of nodes in the tree.  
Next line contains $n$ space separated integer where $i$th integer denotes node[i].data.

**Note**:  Node values are inserted into a binary search tree before a reference to the tree's root node is passed to your function.  In a binary search tree, all nodes on the left branch of a node are less than the node value.  All values on the right branch are greater than the node value.


**Constraints**

 $1 \le node.data[i] \le 20$  
 $1 \le n \le 20$

**Output Format**

Your function should return a single integer denoting the height of the binary tree.

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-12T16:10:25.275Z  

```cpp

/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    int height(Node* root) {
        // Write your code here.
        if(root == NULL){
            return -1;
        }
        return 1+max(height(root->left),height(root->right));        
    }


```

---

[View on HackerRank](https://www.hackerrank.com/challenges/tree-height-of-a-binary-tree/problem)