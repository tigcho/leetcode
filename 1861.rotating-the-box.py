#
# @lc app=leetcode id=1861 lang=python3
#
# [1861] Rotating the Box
#

# @lc code=start
class Solution:
    def rotateTheBox(self, box: List[List[str]]) -> List[List[str]]:
        m, n = len(box), len(box[0])

        ans = [["."] * m for _ in range(n)]

        for r in range(m):
            i = n - 1
            for c in reversed(range(n)):
                if box[r][c] == "#":
                    ans[i][m - r - 1] = "#"
                    i -= 1
                elif box[r][c] == "*":
                    ans[c][m - r - 1] = "*"
                    i = c - 1

        return ans
# @lc code=end

