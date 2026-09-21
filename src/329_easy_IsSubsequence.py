class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        ch2nums = defaultdict(list)
        for i,ch in enumerate(t):
            ch2nums[ch].append(i)
        
        records = []
        for ch in s:
            if ch not in ch2nums:
                return False
            
            if len(records) > 0:
                while ch2nums[ch][0] <= records[-1]:
                    del ch2nums[ch][0]
                    if len(ch2nums[ch]) == 0:
                        return False 

            records.append(ch2nums[ch][0])
            del ch2nums[ch][0]
            if len(ch2nums[ch]) == 0:
                del ch2nums[ch]
        
        return True