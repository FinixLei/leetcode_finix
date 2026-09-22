class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if len(s) != len(t): 
            return False
        
        d1 = {}
        d2 = {}
        for i in range(len(s)):
            if s[i] not in d1:
                if t[i] not in d2:
                    d1[s[i]] = t[i]
                    d2[t[i]] = s[i]
                else:  # t[i] in d2
                    return False
            else:  # s[i] in d1 
                if t[i] not in d2:
                    return False 
                else: # t[i] in d2
                    if d1[s[i]] != t[i] or d2[t[i]] != s[i]:
                        return False
                    
        return True
