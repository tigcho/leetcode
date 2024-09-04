/*
 * @lc app=leetcode id=438 lang=scala
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
object Solution {
    def findAnagrams(s: String, p: String): List[Int] = {
        val sLen = s.length
        val pLen = p.length

        if (sLen < pLen) return List()

        val pCharCount = Array.fill(26)(0)
        val sCharCount = Array.fill(26)(0)
        var startIndices = List[Int]()

        for (c <- p) {
            pCharCount(c - 'a') += 1
        }

        for (i <- 0 until pLen) {
            sCharCount(s(i) - 'a') += 1
        }

        if (pCharCount.sameElements(sCharCount)) {
            startIndices = 0 :: startIndices
        }

        for (i <- pLen until sLen) {
            sCharCount(s(i) - 'a') += 1
            sCharCount(s(i - pLen) - 'a') -= 1

            if (pCharCount.sameElements(sCharCount)) {
                startIndices = (i - pLen + 1) :: startIndices
            }
        }

        startIndices.reverse
    }
}
// @lc code=end

