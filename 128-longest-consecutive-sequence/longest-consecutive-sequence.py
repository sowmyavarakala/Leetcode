class Solution(object):
    def longestConsecutive(self, nums):
        numbers_set = set(nums)
        longest = 0

        for n in nums:
            if (n-1) not in numbers_set:
                length = 1
                while n+length in numbers_set:
                    length += 1
                longest = max(longest,length)
        
        return longest