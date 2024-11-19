#
# @lc app=leetcode id=2461 lang=python3
#
# [2461] Maximum Sum of Distinct Subarrays With Length K
#

# @lc code=start
class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        n = len(nums)
        windowSum = 0
        maxSum = 0
        currWindow = set()
        left = 0

        for right in range(n):
            while nums[right] in currWindow:
                currWindow.remove(nums[left])
                windowSum -= nums[left]
                left += 1

            currWindow.add(nums[right])
            windowSum += nums[right]

            if right - left + 1 == k:
                if len(currWindow) == k:
                    maxSum = max(maxSum, windowSum)
                currWindow.remove(nums[left])
                windowSum -= nums[left]
                left += 1

        return maxSum 
# @lc code=end

