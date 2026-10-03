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
    void helper(TreeNode* root,vector<int>&item){
        if(root!=nullptr){
            helper(root->left,item);
            item.push_back(root->val);
            helper(root->right,item);
        }
        return;
        

    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>item;

        helper(root,item);
        return item;

        

    }
};