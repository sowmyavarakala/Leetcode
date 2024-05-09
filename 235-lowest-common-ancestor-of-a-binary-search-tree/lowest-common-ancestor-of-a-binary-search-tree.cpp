/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* newnode=nullptr;
        if((root->val)==(p->val) || (root->val)==(q->val))
            return root;
        else if((root->val)>(p->val) && (root->val)>(q->val))
            newnode=lowestCommonAncestor(root->left,p,q);
        else if((root->val)<(p->val) && (root->val)<(q->val))
            newnode=lowestCommonAncestor(root->right,p,q);
        else
            newnode=root;
        return newnode;
    }
};