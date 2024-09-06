/*
 * @lc app=leetcode id=828 lang=rust
 *
 * [828] Count Unique Characters of All Substrings of a Given String
 */

// @lc code=start
impl Solution {
    pub fn unique_letter_string(s: String) -> i32 {
        let mut last_position = vec![-1; 26];
        let mut second_last_position = vec![-1; 26];
        let mut unique_count = 0;

        for (i, c) in s.chars().enumerate() {
            let char_index = (c as usize) - ('A' as usize);
            unique_count += (i as i32 - last_position[char_index]) * (last_position[char_index] - second_last_position[char_index]);
            second_last_position[char_index] = last_position[char_index];
            last_position[char_index] = i as i32;
        }

        for i in 0..26 {
            unique_count += (s.len() as i32 - last_position[i]) * (last_position[i] - second_last_position[i]);
        }

        unique_count
    }
}
// @lc code=end

