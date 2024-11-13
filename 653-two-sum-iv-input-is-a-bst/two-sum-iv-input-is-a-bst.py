# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findTarget(self, root: Optional[TreeNode], k: int) -> bool:
        def inorder(node):
            return inorder(node.left) + [node.val] + inorder(node.right) if node else []
        
        elements = inorder(root)
        left, right = 0, len(elements)-1

        while left < right:
            current_sum = elements[left] + elements[right]
            if current_sum == k:
                return True
            elif current_sum < k:
                left += 1
            else:
                right -= 1
        return False