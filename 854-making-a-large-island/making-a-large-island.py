class Solution:
    def largestIsland(self, grid):
        if not grid or not grid[0]:
            return 0
        
        m, n = len(grid), len(grid[0])
        island_sizes = {}
        island_id = 2  # Start with an ID of 2 to avoid conflict with 1s and 0s in the grid

        def dfs(i, j, island_id):
            # Base case: out of bounds or water
            if i < 0 or i >= m or j < 0 or j >= n or grid[i][j] != 1:
                return 0
            
            # Mark the current cell with the island ID
            grid[i][j] = island_id
            size = 1
            
            # Explore neighbors
            size += dfs(i - 1, j, island_id)
            size += dfs(i + 1, j, island_id)
            size += dfs(i, j - 1, island_id)
            size += dfs(i, j + 1, island_id)
            
            return size
        
        # Step 1: Find all islands and their sizes
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    island_size = dfs(i, j, island_id)
                    island_sizes[island_id] = island_size
                    island_id += 1
        
        # Step 2: Try changing each 0 to 1 and calculate the maximum possible island size
        max_island = max(island_sizes.values(), default=0)  # Initial maximum island size
        
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0:
                    seen = set()  # To avoid double-counting the same island
                    
                    # Check the four directions
                    for ni, nj in [(i-1, j), (i+1, j), (i, j-1), (i, j+1)]:
                        if 0 <= ni < m and 0 <= nj < n and grid[ni][nj] > 1:
                            seen.add(grid[ni][nj])
                    
                    # Calculate the total size if this 0 is flipped
                    new_size = 1  # The flipped 0 becomes 1, contributing size 1
                    for island in seen:
                        new_size += island_sizes[island]
                    
                    # Update the maximum size
                    max_island = max(max_island, new_size)
        
        return max_island
        