class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        word_set = set(wordDict)
        n = len(s)

        dp = [[] for _ in range(n + 1)]
        dp[0] = [""]

        # Populate the DP table
        for i in range(1, n + 1):
            for j in range(i):
                if dp[j] and s[j:i] in word_set:
                    dp[i].append(s[j:i])

        def backtrack(end):
            if end == 0:
                return [""]

            sentences = []
            for word in dp[end]:
                for sentence in backtrack(end - len(word)):
                    if sentence:
                        sentences.append(sentence + " " + word)
                    else:
                        sentences.append(word)
            return sentences
        
        if not dp[n]:
            return []

        return backtrack(n)

        