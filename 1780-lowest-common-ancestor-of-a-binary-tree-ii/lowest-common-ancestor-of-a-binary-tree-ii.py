# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.p_found = False
        self.q_found = False
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        def dfs(node):
            if not node:
                return None
            left = dfs(node.left)
            right = dfs(node.right)

            if node == p:
                self.p_found = True
                return node
            if node == q:
                self.q_found = True
                return node
            
            if left and right:
                return node
            
            return left if left else right
        
        lca = dfs(root)

        if self.p_found and self.q_found:
            return lca
        
        return None
        