/*
 * @lc app=leetcode id=1929 lang=cpp
 *
 * [1929] Concatenation of Array
 */

// @lc code=start
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans;
        ans.reserve(2 * nums.size());

        for (int i = 0; i < 2; i++) {
            for (int n : nums) {
                ans.push_back(n);
            }
        }
        return ans;
    }
};
// @lc code=end

