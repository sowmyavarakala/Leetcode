class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        p = 0
        q = 0
        result = ''
        
        while p < len(word1) and q < len(word2):
            result += word1[p] + word2[q]
            p += 1
            q += 1
        
        if p < len(word1):
            result += word1[p:]
        if q < len(word2):
            result += word2[q:]

        return result


        