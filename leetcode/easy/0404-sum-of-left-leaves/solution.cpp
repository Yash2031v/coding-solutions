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