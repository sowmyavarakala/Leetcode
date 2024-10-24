# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        result = []
        def dfs(root):
            if not root:
                result.append('#')
                return
            result.append(str(root.val))
            dfs(root.left)
            dfs(root.right)
        
        dfs(root)
        return ','.join(result)
        

    def deserialize(self, data):
        values = data.split(',')
        self.index  = 0
        def dfs():
            if values[self.index] == '#':
                self.index += 1
                return None
            
            root = TreeNode(int(values[self.index]))
            self.index += 1

            root.left = dfs()
            root.right = dfs()
            return root
            
        return dfs()

        

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))