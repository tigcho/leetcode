#
# @lc app=leetcode id=1072 lang=python3
#
# [1072] Flip Columns For Maximum Number of Equal Rows
#

# @lc code=start
class Solution:
    def maxEqualRowsAfterFlips(self, matrix: List[List[int]]) -> int:
        count = {}
        for row in matrix:
            if row[0] == 0:

                #  if the row starts with 0, just increment the count of the row
                count[tuple(row)] = count.get(tuple(row), 0) + 1
            else:

                #  if the row starts with 1, increment the count of the row with the flipped row
                count[tuple(1 - x for x in row)] = count.get(tuple(1 - x for x in row), 0) + 1

        return max(count.values())
# @lc code=end

