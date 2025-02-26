class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        n = len(nums)
        k = k % n
        rotated = [0] * n
        for i in range(n):
            new_position = (i+k) % n
            rotated[new_position] = nums[i]
        for i in range(n):
            nums[i] = rotated[i]




        