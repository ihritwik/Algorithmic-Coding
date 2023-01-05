from collections import Counter
class Solution:
    def firstUniqChar(self, s: str) -> int:
        data = collections.Counter(s)

        for idx, char in enumerate(s):
            if data[char] == 1:
                return idx
        return -1