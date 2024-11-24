/*
 * @lc app=leetcode id=1975 lang=scala
 *
 * [1975] Maximum Matrix Sum
 */

// @lc code=start
object Solution {
  def maxMatrixSum(matrix: Array[Array[Int]]): Long = {
    var totalAbsoluteSum: Long = 0
    var minAbs: Int = Int.MaxValue
    var negativeCount: Int = 0

    matrix.flatten.foreach { num =>
      totalAbsoluteSum += math.abs(num)
      if (num < 0) negativeCount += 1
      minAbs = math.min(minAbs, math.abs(num))
    }

    if (negativeCount % 2 == 0) totalAbsoluteSum
    else totalAbsoluteSum - 2 * minAbs
  }
}

// @lc code=end

