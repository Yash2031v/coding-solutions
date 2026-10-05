# Sum of Left Leaves

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given the `root` of a binary tree, return  *the sum of all left leaves.* 

A  **leaf**  is a node with no children. A  **left leaf**  is a leaf that is the left child of another node.

 

 **Example 1:** 

```
Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.

```

 **Example 2:** 

```
Input: root = [1]
Output: 0

```

 

 **Constraints:** 

- The number of nodes in the tree is in the range [1, 1000].
- -1000 <= Node.val <= 1000

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 8.1 MB  
**Submitted:** 2026-10-05T14:50:21.480Z  

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int traversalLeft(TreeNode* root){
        if(root->left==NULL){
            return root->val;
        }
        return traversalLeft(root->left);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root->right==NULL && root->left==NULL){
            return 0;
        }
        if(root->right==NULL){
            return traversalLeft(root);
        }
        return traversalLeft(root)+traversalLeft(root->right);
        
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/sum-of-left-leaves/)