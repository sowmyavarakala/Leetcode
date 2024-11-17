class Solution:

    def __init__(self, w: List[int]):
        self.prefix_sums = list(accumulate(w))
        self.total_sum = self.prefix_sums[-1]

    def pickIndex(self) -> int:
        target = random.uniform(0, self.total_sum)
        
        left, right = 0, len(self.prefix_sums) - 1
        while left < right:
            mid = left + (right - left) // 2
            if target > self.prefix_sums[mid]:
                left = mid + 1
            else:
                right = mid
        return left


# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()