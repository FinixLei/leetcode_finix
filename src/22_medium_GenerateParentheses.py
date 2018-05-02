'''
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
For example, given n = 3, a solution set is:
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
'''

class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        final_result = set()

        def _loop(target, left_num, right_num):
            if len(target) == n * 2:
                final_result.add(target)
                return 
                
            if left_num < right_num:
                if left_num > 0:
                    _loop(target+'(', left_num-1, right_num)
                    _loop(target+')', left_num, right_num-1)
                else:  # left_num == 0
                    _loop(target+')', left_num, right_num-1)
                    
            elif left_num == right_num:
                _loop(target+'(', left_num-1, right_num)

        
        _loop('', n, n)
        return list(final_result)
