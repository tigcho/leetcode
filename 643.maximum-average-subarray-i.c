/*
 * @lc app=leetcode id=643 lang=c
 *
 * [643] Maximum Average Subarray I
 */

// @lc code=start
double findMaxAverage(int* nums, int numsSize, int k) {
    double sum = 0;
    for (int i = 0; i < k; i++) {
        sum += nums[i];
    }
    double max = sum;
    for (int i = k; i < numsSize; i++) {
        sum += nums[i] - nums[i - k];
        max = (sum > max) ? sum : max;
    }
    return max / k;
}
// @lc code=end