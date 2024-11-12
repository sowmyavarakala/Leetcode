"""
# Definition for a Node.
class Node:
    def __init__(self, val: Optional[int] = None, children: Optional[List['Node']] = None):
        self.val = val
        self.children = children
"""

class Solution:
    def dfs(self, root, output):
        if not root:
            return
        output.append(root.val)
        for node in root.children:
            self.dfs(node, output)
    def preorder(self, root: 'Node') -> List[int]:
        output = []
        self.dfs(root, output)
        return output