/*
 * @lc app=leetcode id=1876 lang=cpp
 *
 * [1876] Substrings of Size Three with Distinct Characters
 */

// @lc code=start
class Solution {
public:
    int countGoodSubstrings(string s) {

        // first check if the string is less than 3
        int n = s.size();
        if (n < 3) return 0;

        // var for counting the good substrings
        int count = 0;

        for (int i = 0; i < n - 2; i++) {
            if (s[i] != s[i + 1] && s[i + 1] != s[i + 2] && s[i] != s[i + 2]) {
                count++;
            }
        }

        return count;
    }
};
// @lc code=end

