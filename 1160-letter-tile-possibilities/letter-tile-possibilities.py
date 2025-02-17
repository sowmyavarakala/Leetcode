from collections import Counter
class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        def backtrack(counter):
            total_sequences = 0
            for char in counter:
                if counter[char] > 0:
                    # Use this character
                    counter[char] -= 1
                    total_sequences += 1 + backtrack(counter)
                    # Backtrack (restore the character count)
                    counter[char] += 1
            return total_sequences

        return backtrack(Counter(tiles))



        