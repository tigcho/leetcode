#
# @lc app=leetcode id=2554 lang=python3
#
# [2554] Maximum Number of Integers to Choose From a Range I
#

# @lc code=start
class Solution:
    def maxCount(self, banned: List[int], n: int, maxSum: int) -> int:
        banned = set(banned)
        
        res = 0
        for i in range(1, n+1):
            if i in banned:
                continue
            if i > maxSum:
                break
            res += 1
            maxSum -= i
        return res
# @lc code=end

