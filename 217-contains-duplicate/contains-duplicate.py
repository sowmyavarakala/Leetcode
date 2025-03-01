class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        hp = defaultdict(int)
        for i in range(len(nums)):
            hp[nums[i]] += 1
        
        for value in hp.values():
            if value > 1:
                return True
        return False

        