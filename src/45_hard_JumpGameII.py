class Solution:
    def jump(self, nums: List[int]) -> int:
        size = len(nums)
        if size == 1 and nums[0] >= 0:
            return 0
        
        count = 0
        target = size-1
        p1 = 0
        p2 = 0
        min_val = 9999
        max_val = -1

        while True:
            count += 1
            for i in range(p1, p2+1):
                val = i + nums[i]
                if val >= target:
                    return count
                if val > max_val:
                    max_val = val 
                if val < min_val:
                    min_val = val 

            if max_val <= p2:
                return 0
            p1 = p2
            p2 = max_val     
        
        return 0
