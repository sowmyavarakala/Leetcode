class Solution:
    def __init__(self):
        self.memo = {}  # Memoization cache

    def solve(self, s, wordSet):
        # If result for the current substring is already computed, return it
        if s in self.memo:
            return self.memo[s]
        
        # Base case: if the string is empty, return a list with an empty string
        if not s:
            return [""]

        sentences = []  # Store all possible sentences from this point

        # Try all possible prefixes of the string
        for i in range(1, len(s) + 1):
            prefix = s[:i]  # Get the prefix from 0 to i
            if prefix in wordSet:  # Check if the prefix is a valid word
                # Recurse for the remaining part of the string
                remaining_sentences = self.solve(s[i:], wordSet)
                # Combine the current prefix with each sentence from the remaining part
                for sentence in remaining_sentences:
                    if sentence:
                        sentences.append(prefix + " " + sentence)
                    else:
                        sentences.append(prefix)

        # Store the result in memo to avoid redundant computation
        self.memo[s] = sentences
        return sentences

    def wordBreak(self, s, wordDict):
        wordSet = set(wordDict)  # Convert wordDict to a set for O(1) lookups
        return self.solve(s, wordSet)  # Start backtracking from the full string
