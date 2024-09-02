/*
 * @lc app=leetcode id=643 lang=cpp
 *
 * [643] Maximum Average Subarray I
 */

// @lc code=start
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // compute the sum of the first k elements (0 to k-1)
        double windowSum = accumulate(nums.begin(), nums.begin() + k, 0);
        double maxAvg = windowSum / k;

        int i = k;
        while (i < nums.size()) {
            // remove the first element of the window and add the next element
            windowSum = windowSum - nums[i - k] + nums[i];
            maxAvg = max(maxAvg, windowSum / k);
            i++;
        }
        return maxAvg;
    }
};
// @lc code=end

