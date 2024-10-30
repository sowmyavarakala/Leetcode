class Solution:
    def countRangeSum(self, nums: List[int], lower: int, upper: int) -> int:
        
        def merge_sort(prefix, left, right):
            if left >= right:
                return 0

            mid = (left + right) // 2
            count = merge_sort(prefix, left, mid) + merge_sort(prefix, mid + 1, right)

            j = k = mid + 1
            for i in range(left, mid + 1):
                while k <= right and prefix[k] - prefix[i] < lower:
                    k += 1
                while j <= right and prefix[j] - prefix[i] <= upper:
                    j += 1
                count += j - k

            prefix[left:right + 1] = sorted(prefix[left:right + 1])

            return count

        prefix = [0] * (len(nums) + 1)
        for i in range(len(nums)):
            prefix[i + 1] = prefix[i] + nums[i]

        return merge_sort(prefix, 0, len(prefix) - 1)

