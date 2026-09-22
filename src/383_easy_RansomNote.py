class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        ch2count = defaultdict(int)
        for ch in magazine:
            ch2count[ch] += 1
        
        for ch in ransomNote:
            if ch not in ch2count:
                return False
            ch2count[ch] -= 1
            if ch2count[ch] < 0:
                return False 

        return True
        
