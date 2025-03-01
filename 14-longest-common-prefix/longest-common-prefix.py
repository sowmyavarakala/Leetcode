class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        ans = ''
        if not strs:
            return ans
        strs = sorted(strs)
        a = strs[0]
        b = strs[len(strs)-1]
        for i in range(len(a)):
            if a[i] == b[i]:
                ans += a[i]
            else:
                return ans
        
        return ans
