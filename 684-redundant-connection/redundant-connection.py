class Solution:
    def find(self, parent, x):
        if parent[x] != x:
            parent[x] = self.find(parent, parent[x])  # Path compression
        return parent[x]

    def union(self, parent, rank, x, y):
        rootX = self.find(parent, x)
        rootY = self.find(parent, y)
        
        if rootX != rootY:
            if rank[rootX] > rank[rootY]:
                parent[rootY] = rootX
            elif rank[rootX] < rank[rootY]:
                parent[rootX] = rootY
            else:
                parent[rootY] = rootX
                rank[rootX] += 1
            return True
        return False  # If they are already connected, it creates a cycle

    def findRedundantConnection(self, edges):
        n = len(edges)
        parent = [i for i in range(n + 1)]  # Nodes are 1-indexed
        rank = [0] * (n + 1)
        
        for a, b in edges:
            if not self.union(parent, rank, a, b):
                return [a, b]

        