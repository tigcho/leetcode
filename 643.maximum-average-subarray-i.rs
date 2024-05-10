/*
 * @lc app=leetcode id=643 lang=rust
 *
 * [643] Maximum Average Subarray I
 */

// @lc code=start
impl Solution {
    pub fn find_max_average(nums: Vec<i32>, k: i32) -> f64 {
        let k = k as usize;
        let mut sum = 0;
        for i in 0..k {
            sum += nums[i];
        }
        let mut max_sum = sum;
        for i in k..nums.len() {
            sum += nums[i] - nums[i - k];
            max_sum = max_sum.max(sum);
        }
        max_sum as f64 / k as f64
    }
}
// @lc code=end

