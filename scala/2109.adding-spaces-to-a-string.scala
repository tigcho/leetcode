/*
 * @lc app=leetcode id=2109 lang=scala
 *
 * [2109] Adding Spaces to a String
 */

// @lc code=start
object Solution {
    def addSpaces(s: String, spaces: Array[Int]): String = {
        val sb = new StringBuilder
        var prev = 0
        for (space <- spaces) {
            sb.append(s.substring(prev, space)). append(' ')
            prev = space
        }
        sb.append(s.substring(prev))
        sb.toString
    }
}
// @lc code=end

