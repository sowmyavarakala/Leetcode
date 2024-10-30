from typing import List

class Solution:
    def candy(self, ratings: List[int]) -> int:
        n = len(ratings)
        if n == 0:
            return 0

        candies = 1  # Start with 1 candy for the first child
        up = 1  # Length of the current increasing sequence
        down = 0  # Length of the current decreasing sequence
        peak = 1  # Candies given at the last peak

        for i in range(1, n):
            if ratings[i] > ratings[i - 1]:  # Increasing sequence
                up += 1
                down = 0  # Reset the down counter
                peak = up  # Update the peak
                candies += up  # Add candies for the increasing child

            elif ratings[i] < ratings[i - 1]:  # Decreasing sequence
                down += 1
                up = 1  # Reset the up counter
                candies += down  # Add candies for the decreasing child

                # If the down sequence length matches or exceeds the peak length,
                # we need to give one extra candy to the peak child.
                if down >= peak:
                    candies += 1

            else:  # Equal ratings
                up = 1  # Reset the up counter
                down = 0  # Reset the down counter
                peak = 1  # Reset the peak
                candies += 1  # Give exactly 1 candy to this child

        return candies
