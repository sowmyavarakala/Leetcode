from typing import List

class Solution:
    def candy(self, ratings: List[int]) -> int:
        if not ratings:
            return 0
        
        candies = 1
        up = 1
        down = 0
        peak = 1

        for i in range(1, len(ratings)):
            if ratings[i] > ratings[i - 1]:  # Increasing sequence
                up += 1
                down = 0
                candies += up
                peak = up
            elif ratings[i] < ratings[i - 1]:  # Decreasing sequence
                down += 1
                up = 1
                candies += down
                if down >= peak:
                    candies += 1
            else:  # Equal ratings
                up  = 1
                down = 0
                candies += 1
                peak = 1
        
        return candies
