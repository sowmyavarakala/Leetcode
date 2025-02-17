from collections import Counter
class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        def dfs(counter):
            count = 0
            for char in counter:
                if counter[char] > 0:
                    counter[char] -= 1
                    count += 1 + dfs(counter)
                    counter[char] += 1
            return count
        return dfs(Counter(tiles))


        