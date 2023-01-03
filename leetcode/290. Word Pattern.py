class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        map_index = {}
        words = s.split()
        
        if len(pattern) != len(words):
            return False
        
        for i in range(len(words)):
            c = pattern[i]
            w = words[i]
            c = 'char_{}'.format(c)
            w = 'word_{}'.format(w)
            if c not in map_index:
                map_index[c] = i
            
            if w not in map_index:
                map_index[w] = i 
            
            if map_index[c] != map_index[w]:
                return False
        
        return True