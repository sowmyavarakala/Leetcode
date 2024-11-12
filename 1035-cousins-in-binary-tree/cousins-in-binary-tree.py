# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque

class Solution:
    def isCousins(self, root: Optional[TreeNode], x: int, y: int) -> bool:
        res = []

        queue = deque([(root, None, 0)])

        while queue:
            if len(res) == 2:
                break
            node, parent, depth = queue.popleft()
            if node.val == x or node.val == y:
                res.append((parent, depth))
            
            if node.left:
                queue.append((node.left, node, depth + 1))
            
            if node.right:
                queue.append((node.right, node, depth + 1))
        
        n1, n2 = res

        return n1[0] != n2[0] and n1[1] == n2[1]
        