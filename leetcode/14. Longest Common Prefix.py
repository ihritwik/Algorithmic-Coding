class Solution:
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if not strs: return ""
        if len(strs) == 1: return strs[0]
        
        strs.sort()
        prefix = ""
        for x, y in zip(strs[0], strs[-1]):
            if x == y: 
                prefix=prefix+x
            else: break
        return prefix