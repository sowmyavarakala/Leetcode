class Solution:
    def largestIsland(self, grid: List[List[int]]) -> int:
        if not grid or not grid[0]:
            return 0

        m, n = len(grid), len(grid[0])

        def dfs(i, j, island_id):
            stack = [(i, j)]
            size = 0
            while stack:
                x, y = stack.pop()
                if x < 0 or x >= m or y < 0 or y >= n or grid[x][y] == 0 or visited[x][y]:
                    continue
                visited[x][y] = True
                size += 1
                island_map[(x, y)] = island_id
                stack.append((x - 1, y))  # Up
                stack.append((x + 1, y))  # Down
                stack.append((x, y - 1))  # Left
                stack.append((x, y + 1))  # Right
            return size

        # Step 1: Find all islands, assign them unique IDs, and calculate their sizes
        visited = [[False] * n for _ in range(m)]
        island_map = {}  # Map from cell to island ID
        island_sizes = {}  # Map from island ID to its size
        island_id = 0

        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1 and not visited[i][j]:
                    size = dfs(i, j, island_id)
                    island_sizes[island_id] = size
                    island_id += 1

        # Step 2: Calculate the maximum island size after flipping one `0` to `1`
        max_island_size = max(island_sizes.values(), default=0)

        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0:
                    # Collect unique neighboring island IDs
                    seen_islands = set()
                    for x, y in [(i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)]:
                        if 0 <= x < m and 0 <= y < n and grid[x][y] == 1:
                            island_id = island_map[(x, y)]
                            seen_islands.add(island_id)

                    # Calculate the potential new island size
                    new_size = 1  # Starting with the flipped cell itself
                    new_size += sum(island_sizes[island_id] for island_id in seen_islands)
                    max_island_size = max(max_island_size, new_size)

        return max_island_size


# # Example usage:
# grid = [
#     [1, 0, 0, 1],
#     [1, 0, 0, 1],
#     [0, 1, 1, 1],
#     [0, 0, 1, 1]
# ]

# print("The maximum size of the island with one flip is:", maxIslandSizeWithOneFlip(grid))
        