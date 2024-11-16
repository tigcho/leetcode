#
# @lc app=leetcode id=3254 lang=python3
#
# [3254] Find the Power of K-Size Subarrays I
#

# @lc code=start
class Solution:
    def resultsArray(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        results = []

        for i in range(n - k + 1):
            subarr = nums[i:i+k]

            if all(subarr[j] + 1 == subarr[j + 1] for j in range(k - 1)):
                results.append(max(subarr))
            else:
                results.append(-1)

        return results

# @lc code=end

