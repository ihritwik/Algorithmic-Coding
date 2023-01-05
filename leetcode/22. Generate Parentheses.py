class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def dfs(left, right, s):
            if len(s) == n * 2:
                res.append(s)
                print(s)
                return 

            if left < n:
                print (left+1, ', ', right, ' (')
                dfs(left + 1, right, s + '(')

            if right < left:
                print (left, ', ', right+1, ' )')
                dfs(left, right + 1, s + ')')

        res = []
        dfs(0, 0, '')
        return res