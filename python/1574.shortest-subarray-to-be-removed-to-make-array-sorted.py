#
# @lc app=leetcode id=1574 lang=python3
#
# [1574] Shortest Subarray to be Removed to Make Array Sorted
#

# @lc code=start
class Solution:
    def findLengthOfShortestSubarray(self, arr: List[int]) -> int:
        n = len(arr)
        left = 0

        while left < n - 1 and arr[left] <= arr[left + 1]:
            left += 1
        if left == n - 1:
            return 0
        
        right = n - 1

        while right > 0 and arr[right - 1] <= arr[right]:
            right -= 1

        subarr = min(n - left - 1, right)

        for i in range(left + 1):
            if arr[i] <= arr[right]:
                subarr = min(subarr, right - i - 1)
            elif right < n - 1:
                right += 1
            else:
                break

        return subarr
# @lc code=end

