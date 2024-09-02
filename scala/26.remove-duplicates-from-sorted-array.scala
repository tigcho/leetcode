/*
 * @lc app=leetcode id=26 lang=scala
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
object Solution {
    def removeDuplicates(nums: Array[Int]): Int = {

        // nums.tail contains all elements except the first operation
        // foldLeft iterates with the tuple as an initial value
        nums.tail.foldLeft((nums.head, 1)) {
            case ((i, j), current) =>
                if (current != i) {
                    nums(j) = current
                    (current, j + 1)
                } else {
                    (i, j)
                }
        }._2
    }
}
// @lc code=end

