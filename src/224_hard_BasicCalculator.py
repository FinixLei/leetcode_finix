class Solution:
    def calculate(self, s: str) -> int:
        res = 0
        ops = [1]
        sign = 1
        i = 0
        size = len(s)
        
        while i < size:
            if s[i] == ' ':
                i += 1
            elif s[i] == '+':
                sign = ops[-1]
                i += 1
            elif s[i] == '-':
                sign = -ops[-1]
                i += 1
            elif s[i] == '(':
                ops.append(sign)
                i += 1
            elif s[i] == ')':
                ops.pop()
                i += 1
            else:
                n = 0
                while i < size and s[i].isdigit():
                    n = n * 10 + int(s[i])
                    i += 1
                res = res + sign * n

        return res 