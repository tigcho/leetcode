/*
 * @lc app=leetcode id=3254 lang=rust
 *
 * [3254] Find the Power of K-Size Subarrays I
 */

// @lc code=start
impl Solution {
    pub fn results_array(nums: Vec<i32>, k: i32) -> Vec<i32> {
        nums.windows(k as usize)
            .map(|subarr| {
                if subarr.windows(2).all(|pair| pair[1] == pair[0] + 1) {
                    *subarr.iter().max().unwrap()
                } else {
                    -1
                }
            })
            .collect()
    }
}

// @lc code=end

