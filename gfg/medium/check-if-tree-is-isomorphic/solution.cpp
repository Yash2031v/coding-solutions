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