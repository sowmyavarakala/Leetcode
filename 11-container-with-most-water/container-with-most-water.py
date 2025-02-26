class Solution:
    def maxArea(self, height: List[int]) -> int:
        l = 0
        r = len(height) - 1
        water = 0
        while l < r:
            width = r - l
            h = min(height[l], height[r])
            water = max(water, width*h)
            if height[l] > height[r]:
                r -= 1
            else:
                l += 1
        return water



        