# Isomorphic Trees

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given two binary trees with roots  **root1**  and  **root2**, check whether the two trees are isomorphic. Two binary trees are called isomorphic if one tree can be obtained from the other by swapping the left and right children of any number of nodes.

The children of a node can be swapped independently at any level of the tree.

 **Examples:** 

```
Input: root1 = [1, 2, 3, 4, 5, 6, N, N, 7, 8], root2 = [1, 3, 2, N, 6, 4, 5, N, N, N, N, 8, 7]
 
Output: true
Explanation: Swapping the left and right children of nodes 1, 3, and 5 makes both trees structurally identical.
```

```
Input: root1 = [1, 2, 3, 4], root2 = [1, 3, 2, 4]

Output: false
Explanation: The positions of node 4 cannot be matched by swapping the children of any nodes, so the two trees are not isomorphic.
```

```
Input: root1 = [1, 2, 3, 4], root2 = [1, 3, 2, N, N, N, 4]

Output: true
Explanation: Swapping the children of node 1 makes node 4 occupy the corresponding position in both trees.
```

 **Constraints:** 
1 ≤ number of nodes ≤ 105
1 ≤ node->data ≤ 105

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-08T05:35:05.996Z  

```cpp
class Solution {
public:
    bool isIsomorphic(Node* root1, Node* root2) {

        // Both are NULL
        if (root1 == NULL && root2 == NULL)
            return true;

        // One is NULL, other isn't
        if (root1 == NULL || root2 == NULL)
            return false;

        // Values must be same
        if (root1->data != root2->data)
            return false;

        // Case 1: No swapping
        bool noSwap = isIsomorphic(root1->left, root2->left) &&
                      isIsomorphic(root1->right, root2->right);

        // Case 2: Swapping
        bool swap = isIsomorphic(root1->left, root2->right) &&
                    isIsomorphic(root1->right, root2->left);

        return noSwap || swap;
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/check-if-tree-is-isomorphic/1)