class Solution:
    def resultsArray(self, nums: List[int], k: int) -> List[int]:
        left = 0
        result = []
        con_count = 1
        for right in range(len(nums)):
            if right > 0 and nums[right] == nums[right - 1] + 1:
                con_count += 1
            
            if right - left + 1 > k:
                if nums[left] + 1 == nums[left + 1]:
                    con_count -= 1
                left += 1
            
            if right - left + 1 == k:
                result.append(nums[right] if con_count == k else -1)
        
        return result