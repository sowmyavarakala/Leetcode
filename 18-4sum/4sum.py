class Solution:
    def fourSum(self, nums, target):
        nums.sort()
        result = []
        n = len(nums)
        
        for i in range(n - 3):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
                
            for j in range(i + 1, n - 2):
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue
                    
                left, right = j + 1, n - 1
                while left < right:
                    currentSum = nums[i] + nums[j] + nums[left] + nums[right]
                    if currentSum == target:
                        result.append([nums[i], nums[j], nums[left], nums[right]])
                        
                        # Move pointers and avoid duplicates
                        left += 1
                        right -= 1
                        while left < right and nums[left] == nums[left - 1]:
                            left += 1
                        while left < right and nums[right] == nums[right + 1]:
                            right -= 1
                    
                    elif currentSum < target:
                        left += 1 
                    else:
                        right -= 1 
                        
        return result

        