"""
# Definition for a Node.
class Node(object):
    def __init__(self, val: Optional[int] = None, children: Optional[List['Node']] = None):
        if children is None:
            children = []
        self.val = val
        self.children = children
"""

class Codec:
    def serialize(self, root: 'Node') -> str:
        """Encodes an N-ary tree to a single string."""
        def dfs(node: 'Node') -> str:
            if not node:
                return ""
            # Add the current node's value and number of children
            serialized_data = f"{node.val} {len(node.children)} "
            # Recursively add each child's serialized data
            for child in node.children:
                serialized_data += dfs(child)
            return serialized_data
        
        return dfs(root).strip()

    def deserialize(self, data: str) -> 'Node':
        """Decodes your encoded data to an N-ary tree."""
        if not data:
            return None
        
        def dfs() -> 'Node':
            val = next(data_iter)
            child_count = int(next(data_iter))
            node = Node(int(val), [])
            for _ in range(child_count):
                node.children.append(dfs())
            return node
        
        data_iter = iter(data.split())
        return dfs()
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))