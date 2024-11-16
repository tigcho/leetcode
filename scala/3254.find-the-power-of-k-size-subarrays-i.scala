/*
 * @lc app=leetcode id=3254 lang=scala
 *
 * [3254] Find the Power of K-Size Subarrays I
 */

// @lc code=start
object Solution {
    def resultsArray(nums: Array[Int], k: Int): Array[Int] = {
        nums.sliding(k).map { subarr =>
            if (subarr.zip(subarr.tail).forall {
                case (a, b) => b == a + 1
            }) {
                subarr.max
            } else {
                -1
            }
        }.toArray
    }
}
// @lc code=end

