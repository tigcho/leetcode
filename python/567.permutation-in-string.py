#
# @lc app=leetcode id=567 lang=python3
#
# [567] Permutation in String
#

# @lc code=start
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        s1_len = len(s1)
        s2_len = len(s2)

        if s1_len > s2_len:
            return False
        
        s1_count = [0] * 26
        s2_count = [0] * 26

        for char in s1: 
            # ord return the unicode of the character
            # ord - ord('a') will give the index of the character in the array
            # increment to count the number of characters
            s1_count[ord(char) - ord('a')] += 1

        for i in range(s2_len):
            s2_count[ord(s2[i]) - ord('a')] += 1
            if i >= s1_len:
                s2_count[ord(s2[i - s1_len]) - ord('a')] -= 1

            if s1_count == s2_count:
                return True
            
        return False
# @lc code=end

