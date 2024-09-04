#
# @lc app=leetcode id=438 lang=python3
#
# [438] Find All Anagrams in a String
#

# @lc code=start
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        # Sort for easier comparison of p and s
        sorted_p = ''.join(sorted(p))
        currWindow = []
        startIndices = []
        startWindow = 0

        for char in s:
            # Add the current character to the window
            currWindow.append(char)
            # Check if window is the same size as anagram p
            if len(currWindow) == len(p):
                # Check if the current window equals the sorted anagram
                if ''.join(sorted(currWindow)) == sorted_p:
                    # Add the start index of the window to the list
                    startIndices.append(startWindow)
                # Remove the oldest character from the window
                currWindow.pop(0)
                startWindow += 1

        return startIndices

# @lc code=end

