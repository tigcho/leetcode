#
# @lc app=leetcode id=2109 lang=python3
#
# [2109] Adding Spaces to a String
#

# @lc code=start
class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        m, n = len(s), len(spaces)
        if n == 0:
            return s
        res = []
        spaces = [0] + spaces + [m]

        for i in range(1, len(spaces)):
            res.append(s[spaces[i-1]:spaces[i]])
            if i < len(spaces) - 1:
                res.append(' ')
        return ''.join(res)
# @lc code=end

