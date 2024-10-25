class Solution:
    # using stack
    def calculate(self, s: str) -> int:
        num = 0
        sign = 1
        res = 0
        stack = []

        for i in range(len(s)):
            c = s[i]
            if c.isdigit():
                num = num*10 + int(c)
            elif c in '+-':
                res += num * sign
                sign = 1 if c is '+' else -1
                num = 0
            elif c == '(':
                stack.append(res)
                stack.append(sign)
                sign = 1
                res = 0
            elif c == ')':
                res += num * sign
                res *= stack.pop()
                res += stack.pop()
                num = 0
        
        return res + num * sign

        