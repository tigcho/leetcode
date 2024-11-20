#
# @lc app=leetcode id=2516 lang=python3
#
# [2516] Take K of Each Character From Left and Right
#

# @lc code=start
class Solution:
    def takeCharacters(self, s: str, k: int) -> int:
        count = Counter(s)

        if count['a'] < k or count['b'] < k or count['c'] < k:
            return -1
        
        n = len(s)
        required = {'a': count['a'] - k, 'b': count['b'] - k, 'c': count['c'] - k}
        left = 0
        maxLen = 0
        currCount = {'a': 0, 'b': 0, 'c': 0}

        for right in range(n):
            currCount[s[right]] += 1

            while any(count[char] - currCount[char] < k for char in 'abc'):
                currCount[s[left]] -= 1
                left += 1

            maxLen = max(maxLen, right - left + 1)

        return n - maxLen
# @lc code=end

