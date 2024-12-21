class Solution:
    def finalPrices(self, A: List[int]) -> List[int]:
        stack = []
        for i, a in enumerate(A):
            while stack and A[stack[-1]] >= a:
                A[stack.pop()] -= a
            stack.append(i)
        return A
        