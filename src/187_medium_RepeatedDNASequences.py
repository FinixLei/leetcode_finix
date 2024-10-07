class Solution(object):
    def findRepeatedDnaSequences(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        size = len(s)
        if size < 10:
            return []
            
        dna_dict = dict()
        i=0
        while i < size-9:
            tmp = s[i:i+10]
            if dna_dict.get(tmp) is None:
                dna_dict[tmp] = 1
            else:
                dna_dict[tmp] += 1
            i += 1
        
        result = list()
        for k,v in dna_dict.items():
            if v >= 2:
                result.append(k)
        
        return result