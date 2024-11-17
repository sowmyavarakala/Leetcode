class Solution:
    def countKDifference(self, nums: List[int], k: int) -> int:
        seen = defaultdict(int)

        count = 0
        for num in nums:
            if num - k in seen:
                count += seen[num-k]
            if num + k in seen:
                count += seen[num+k]
            seen[num] = seen.get(num, 0) + 1
        return count