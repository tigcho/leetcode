#
# @lc app=leetcode id=1876 lang=python
#
# [1876] Substrings of Size Three with Distinct Characters
#

# @lc code=start
class Solution(object):
    def countGoodSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        count = 0
        n = len(s)

        for i in range(n - 2):
            if len(set(s[i:i+3])) == 3:
                count += 1
                
        return count


# @lc code=end

