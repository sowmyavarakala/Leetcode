class Solution:
    def hasIncreasingSubarrays(self, nums: List[int], k: int) -> bool:
        n = len(nums)
        if n < 2 * k:
            return False
        def helper(a):
            for i in range(a, a + k -1):
                if nums[i] >= nums[i+1]:
                    return False
            
            return True

        for a in range(n - 2 * k + 1):
            if helper(a) and helper(a + k):
                return True
        
        return False

