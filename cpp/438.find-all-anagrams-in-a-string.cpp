/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> startIndices;
        if (s.length() < p.length()) {
            return startIndices;
        }

        vector<int> pCharCount(26, 0);
        vector<int> sCharCount(26, 0);

        // correspons to a letter in the alphabet
        // c - 'a' will give the index of the letter in the alphabet
        // by incrementing it, we count the occurence of the letter
        for (char c : p) {
            pCharCount[c - 'a']++;
        }

        // each character s[i] will be converted to an index
        // this is a freq counter for a window from 0 to p.length() - 1
        // we slide this window to the right and increment the occurence
        // of the letter in the window s
        for (int i = 0; i < p.length(); i++) {
            sCharCount[s[i] - 'a']++;
        }

        // if the freq counter of the window is equal to the freq counter of p
        // then we have an anagram
        if (pCharCount == sCharCount) {
            startIndices.push_back(0);
        }


        for (int i = p.length(); i < s.length(); i++) {
            sCharCount[s[i] - 'a']++;
            // calculate the index of the letter that is leaving the window
            // i - position of right end of window
            // p.length - length of the window
            // i - p.length() - index of char that was at the left end
            // sCharCount[...] - convert the char to an index and decrement count

            // exmaple: char is b, then s[i - p.length()] - 'a' will be 1 since b - a = 1
            sCharCount[s[i - p.length()] - 'a']--;

            if (pCharCount == sCharCount) {
                // i - p.length() + 1 will give the starting index of the window
                // example: s = "cbaebabacd", p = "abc"
                // i = 6, p.length() = 3, i - p.length() + 1 = 4
                // the window is "ebab"
                startIndices.push_back(i - p.length() + 1);
            }
        }
        return startIndices;
    }
};
// @lc code=end

