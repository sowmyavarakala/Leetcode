class Solution:
        def maxFrequency(self, A: List[int], k: int, numOperations: int) -> int:
            A.sort()
            n = len(A)

            # case 1
            count = Counter()
            res = i = j = 0
            for a in A:
                while j < n and A[j] <= a + k:
                    count[A[j]] += 1
                    j += 1
                while i < n and A[i] < a - k:
                    count[A[i]] -= 1
                    i += 1
                cur = min(j - i, count[a] + numOperations)
                res = max(res, cur)

            # case 2
            i = 0
            for j in range(n):
                while A[i] + k + k < A[j]:
                    i += 1
                res = max(res, min(j - i + 1, numOperations))
            return res