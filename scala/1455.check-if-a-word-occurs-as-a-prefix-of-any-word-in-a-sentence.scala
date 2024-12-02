/*
 * @lc app=leetcode id=1455 lang=scala
 *
 * [1455] Check If a Word Occurs As a Prefix of Any Word in a Sentence
 */

// @lc code=start
object Solution {
  def isPrefixOfWord(sentence: String, searchWord: String): Int = {
    sentence.split(" ").zipWithIndex.find {
      case (word, _) => word.startsWith(searchWord)
    }.map {
      case (_, index) => index + 1
    }.getOrElse(-1)
  }
}
// @lc code=end

