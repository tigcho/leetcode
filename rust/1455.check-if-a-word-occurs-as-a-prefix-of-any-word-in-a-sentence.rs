/*
 * @lc app=leetcode id=1455 lang=rust
 *
 * [1455] Check If a Word Occurs As a Prefix of Any Word in a Sentence
 */

// @lc code=start
impl Solution {
    pub fn is_prefix_of_word(sentence: String, search_word: String) -> i32 {
        return sentence.split_whitespace().enumerate().find_map(|(i, word)| {
            if word.starts_with(&search_word) {
                Some(i as i32 + 1)
            } else {
                None
            }
        }).unwrap_or(-1);
    }
}
// @lc code=end

