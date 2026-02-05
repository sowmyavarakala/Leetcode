class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        numbers_set = set(nums)
        longest = 0

        for n in numbers_set:
            if (n-1) not in numbers_set:
                length = 1
                while n + length in numbers_set:
                    length += 1
                longest = max(longest, length)
        return longest

        # numbers_set = set(nums)
        # longest = 0

        # for n in numbers_set:
        #     if (n-1) not in numbers_set:
        #         length = 1
        #         while n+length in numbers_set:
        #             length += 1
        #         longest = max(longest,length)
        
        # return longest