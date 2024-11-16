/*
 * @lc app=leetcode id=3254 lang=cpp
 *
 * [3254] Find the Power of K-Size Subarrays I
 */

// @lc code=start
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        std::vector<int> results;
        int n = nums.size();

        for (int i = 0; i <= n - k; ++i) {
            bool isConsecutive = true;
            for (int j = 0; j < k - 1; ++j) {
                if (nums[i + j] + 1 != nums[i + j + 1]) {
                    isConsecutive = false;
                    break;
                }
            }
            if (isConsecutive) {
                results.push_back(*std::max_element(nums.begin() + i, nums.begin() + i + k));
            } else {
                results.push_back(-1);
            }
        }

        return results;
    }
};
// @lc code=end

