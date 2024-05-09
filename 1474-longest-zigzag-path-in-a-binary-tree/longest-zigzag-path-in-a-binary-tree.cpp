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
    int maxi = 0;
    void dfs(TreeNode* root, int direction, int length){
        if(!root) return;
        maxi = max(maxi,length);
        if(!direction){
            dfs(root->left, direction, 1);
            dfs(root->right, direction^1, length+1);
        }else{
            dfs(root->left, direction^1, length+1);
            dfs(root->right, direction, 1);
        }
        return;
    }
    int longestZigZag(TreeNode* root) {
        dfs(root->left, 0, 1);
        dfs(root->right, 1, 1);
        return maxi;
    }
};