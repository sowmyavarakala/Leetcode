class Solution:
    def solve(self, items, query):
        s, e = 0, len(items) - 1
        ans = 0

        while s<=e:
            mid = s + (e-s) // 2
            if items[mid][0] <= query:
                ans = items[mid][1]
                s = mid + 1
            else:
                e = mid - 1
        
        return ans

    def maximumBeauty(self, items: List[List[int]], queries: List[int]) -> List[int]:
        items.sort()
        for i in range(1, len(items)):
            items[i][1] = max(items[i-1][1], items[i][1])
        
        ans = []
        for query in queries:
            ans.append(self.solve(items, query))
        
        return ans