/*
 * @lc app=leetcode id=1876 lang=rust
 *
 * [1876] Substrings of Size Three with Distinct Characters
 */

// @lc code=start
impl Solution {
    pub fn count_good_substrings(s: String) -> i32 {
        let n = s.len();
        if n < 3 {
            return 0;
        }

        let mut count = 0;
        let chars: Vec<char> = s.chars().collect();

        for i in 0..n-2 {
            if chars[i] != chars[i + 1] && chars[i + 1] != chars[i + 2] && chars[i] != chars[i + 2] {
                count += 1;
            }
        }
        count
    }
}
// @lc code=end

