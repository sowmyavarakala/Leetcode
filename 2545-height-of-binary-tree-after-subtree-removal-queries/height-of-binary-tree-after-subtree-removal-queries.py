# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def treeQueries(self, root: Optional[TreeNode], queries: List[int]) -> List[int]:
        depth, height = defaultdict(int), defaultdict(int)
        def dfs(node, d):
            if not node:
                return -1
            depth[node.val] = d
            curr = max(dfs(node.left, d + 1), dfs(node.right, d + 1)) + 1
            height[node.val] = curr
            return curr

        dfs(root, 0)
        cousins = defaultdict(list)

        for val, d in depth.items():
            cousins[d].append((-height[val], val))
            cousins[d].sort()
            if len(cousins[d]) > 2:
                cousins[d].pop()
        
        ans = []
        for q in queries:
            d = depth[q]
            if len(cousins[d]) == 1:
                ans.append(d - 1)
            elif cousins[d][0][1] == q:
                ans.append(-cousins[d][1][0]+d)
            else:
                ans.append(-cousins[d][0][0]+d)
        
        return ans
