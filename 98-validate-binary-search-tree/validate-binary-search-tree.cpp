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
    bool dfs(TreeNode* root, long long lower, long long upper){
        if(!root) return true;
        if(root->val > lower && root->val < upper){
            return dfs(root->left, lower, root->val) && dfs(root->right, root->val, upper);
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
       return dfs(root,LONG_MIN, LONG_MAX); 
    }
};