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
    int sum(TreeNode* root ,bool fun){
        if(root == NULL) 
            return 0;
        if(root->left == NULL && root->right == NULL) {
            if(fun){ 
                return root->val;
                }
            return 0;
        }
        return sum(root->left, true) + sum(root->right, false);
        
    }


        

    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL) 
            return 0;
        return sum(root->left,true) + sum(root->right,false);
    }
};