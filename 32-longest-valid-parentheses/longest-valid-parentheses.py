class Solution:
    def longestValidParentheses(self, s: str) -> int:
        stack = [-1]  # Stack to store indices
        max_len = 0

        for i in range(len(s)):
            if s[i] == '(':
                stack.append(i)  # Push the index of '('
            else:
                stack.pop()  # Pop the top element (matching '(' or -1)
                if not stack:
                    stack.append(i)  # Push the current index if stack is empty
                else:
                    max_len = max(max_len, i - stack[-1])  # Calculate valid length

        return max_len 