class Solution:
    def __init__(self):
        self.ans = []
    def helper(self, open, close, n , current):
        if(len(current) == n * 2):
            self.ans.append(current)
            return
        
        if open < n:
            self.helper(open+1, close, n, current + '(')
        if close < open:
            self.helper(open, close+1, n, current + ')')
    def generateParenthesis(self, n: int) -> List[str]:
        self.helper(0, 0, n, '')
        return self.ans
        