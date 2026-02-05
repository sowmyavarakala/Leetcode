class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
#         num_set = set(nums)
#         longest = 0

#         for num in num_set:
#             if (num-1) not in num_set:
#                 length = 1
#                 while num + length in num_set:
#                     length += 1
#                     longest = max(longest, length)
#         return longest

# class Solution(object):
#     def longestConsecutive(self, nums):
        numbers_set = set(nums)
        longest = 0

        for n in numbers_set:
            if (n-1) not in numbers_set:
                length = 1
                while n+length in numbers_set:
                    length += 1
                longest = max(longest,length)
        
        return longest