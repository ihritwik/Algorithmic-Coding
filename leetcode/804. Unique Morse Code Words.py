import string
class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        info = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
        # create a map
        data = {}
        for key, value in zip(string.ascii_lowercase, info):
            data[key] = value

        # create a set to store the transformations
        response = set()
        # iterate through words
        for word in words:
            ans = ""
            for character in word:
                ans = ans+data[character]
            response.add(ans)
        
        return (len(response))
