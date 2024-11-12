# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if not root: 
            return 0
        maxLeft = self.minDepth(root.left)
        maxRight = self.minDepth(root.right)
        if not root.left or not root.right:
            return max(maxLeft, maxRight) + 1
        return min(maxLeft, maxRight)+1