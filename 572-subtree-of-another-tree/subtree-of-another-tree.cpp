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
    bool isSameTree(TreeNode* s, TreeNode* r){
        if(!s && !r) return true;
        if(!s || !r) return false;
        if(s->val == r->val) return isSameTree(s->left,r->left) && isSameTree(s->right,r->right);
        return false;
    }

    bool isSubtree(TreeNode* s, TreeNode* r) {

        if(!s) return false;
        if(isSameTree(s,r)) return true;
        return isSubtree(s->left,r) || isSubtree(s->right,r);
    }
};