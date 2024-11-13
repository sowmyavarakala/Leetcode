# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def verticalOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        
        queue = deque([(root, 0)])
        columns = defaultdict(list)
        while queue:
            node, index = queue.popleft()
            columns[index].append(node.val)

            if node.left:
                queue.append((node.left, index - 1))
            if node.right:
                queue.append((node.right, index + 1))
        
        low = min(columns.keys())
        high = max(columns.keys())
        result = [columns[i] for i in range(low, high+1)]

        return result

        
        