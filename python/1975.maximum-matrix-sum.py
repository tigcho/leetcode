#
# @lc app=leetcode id=1975 lang=python3
#
# [1975] Maximum Matrix Sum
#

# @lc code=start
class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        totalAbsoluteSum = 0
        totalNegativeCount = 0
        minPositive = float('inf')

        for row in matrix:
            for num in row:
                totalAbsoluteSum += abs(num)
                if num < 0:
                    totalNegativeCount += 1
                    minPositive = min(minPositive, abs(num))
                else:
                    minPositive = min(minPositive, num)

        if totalNegativeCount % 2 == 0:
            return totalAbsoluteSum
        else:
            return totalAbsoluteSum - 2 * minPositive
# @lc code=end

