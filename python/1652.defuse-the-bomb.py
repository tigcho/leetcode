#
# @lc app=leetcode id=1652 lang=python3
#
# [1652] Defuse the Bomb
#

# @lc code=start
class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        n = len(code)
        result = [0] * n

        if k == 0:
            return result

        for i in range(n):
            if k > 0:
                for j in range(1, k + 1):
                    result[i] += code[(i + j) % n]
            else:
                for j in range(1, -k + 1):
                    result[i] += code[(i - j) % n]

        return result
# @lc code=end

