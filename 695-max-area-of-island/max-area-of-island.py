class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        
        if not grid or not grid[0]:
            return 0
        
        # Get the dimensions of the grid
        m, n = len(grid), len(grid[0])
        
        def dfs(i, j):
            # Base case: if the index is out of bounds or it's water, return 0
            if i < 0 or i >= m or j < 0 or j >= n or grid[i][j] == 0:
                return 0
            
            # Mark the current land cell as visited by setting it to 0 (water)
            grid[i][j] = 0
            
            # Initialize size of the current island part
            size = 1
            
            # Explore all four directions (up, down, left, right)
            size += dfs(i - 1, j)  # up
            size += dfs(i + 1, j)  # down
            size += dfs(i, j - 1)  # left
            size += dfs(i, j + 1)  # right
            
            return size
        
        # Variable to store the size of the largest island
        largest_island = 0
        
        # Iterate over each cell in the grid
        for i in range(m):
            for j in range(n):
                # Start a DFS when we find an unvisited land cell
                if grid[i][j] == 1:
                    largest_island = max(largest_island, dfs(i, j))
        
        return largest_island
