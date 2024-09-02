#
# @lc app=leetcode id=643 lang=python3
#
# [643] Maximum Average Subarray I
#

# @lc code=start
class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        windowSum = sum(nums[:k])
        maxSum = windowSum / k

        for i in range(k, len(nums)):
            windowSum = windowSum + nums[i] - nums[i - k]
            maxSum = max(maxSum, windowSum / k)
            
        return maxSum
        
# @lc code=end