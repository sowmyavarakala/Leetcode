class Solution:
    # using stack
    def calculate(self, s: str) -> int:
        def helper(i):
            num = 0
            sign = 1
            res = 0

            while i < len(s):
                c = s[i]
                if c.isdigit():
                    num = num*10 + int(c)
                elif c in '+-':
                    res += num * sign
                    sign = 1 if c is '+' else -1
                    num = 0
                elif c == '(':
                    num, i = helper(i + 1)
                elif c == ')':
                    res += num * sign
                    return res, i
                i += 1
        
            return res + num * sign, i
        result, _ = helper(0)
        return result

        