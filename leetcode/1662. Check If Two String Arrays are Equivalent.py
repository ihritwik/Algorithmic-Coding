class Solution(object):
    def arrayStringsAreEqual(self, word1, word2):
        """
        :type word1: List[str]
        :type word2: List[str]
        :rtype: bool
        """
        length_word1 = len(word1)
        length_word2 = len(word2)
        
        concat_word1 = ""
        concat_word2 = ""
        for i in word1:
            concat_word1 += i
        for j in word2:
            concat_word2 += j
        if concat_word1 == concat_word2:
            return True
        else:   
            return False