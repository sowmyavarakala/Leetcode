class Solution:
    def canPartition(self, s: str, target: int) -> bool:
        if not s and target == 0:
            return True
        if target < 0:
            return False
        
        # Try all possible pivot points
        for i in range(len(s)):
            left = s[:i + 1]  # Keep the left part
            right = s[i + 1:]  # Recurse for the right part
            left_num = int(left)
            
            if self.canPartition(right, target - left_num):
                return True
        
        return False

    def punishmentNumber(self, n: int) -> int:
        total_sum = 0
        for num in range(1, n + 1):
            sqr = num * num
            if self.canPartition(str(sqr), num):
                total_sum += sqr
        return total_sum
