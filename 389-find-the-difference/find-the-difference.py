class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        str1 = sum(ord(c) for c in s)
        str2 = sum(ord(c) for c in t)

        return chr(str2-str1)
        