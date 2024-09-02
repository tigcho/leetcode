/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        /* stores indices of iteration through s, finding all positions 
        where anagrams of p are present in s */ 
        vector<int> indi;

        // in these cases there can be no anagrams of p in s
        if (s.empty() || p.empty() || s.size() < p.size()) {
            return indi;
        }

        // stores the frequency of characters
        vector<int> pCount(26, 0), sCount(26, 0);

        // p.size is the window size of characters
        for (int i = 0; i < p.size(); i++) {
            /* subtracting the ASCII value of 'a' from the ASCII 
            value of p[i], which gives us an index between 0 and 25*/
            pCount[p[i] - 'a']++;
            sCount[s[i] - 'a']++;
        }

        // if the count of characters in p and s are equal, there is an anagram
        if (pCount == sCount) {
            // pushes indice of character when window of s is an anagram of p
            indi.push_back(0);
        }

        // moves a window of size p.size over s
        for (int i = p.size(); i < s.size(); i++) {
            // increment count of character at index i in s
            sCount[s[i] - 'a']++;
            // decrement count of character that was removed from window
            sCount[s[i - p.size()] - 'a']--;

            if (pCount == sCount) {
                // i - p.size only gives the index just before the window starts
                indi.push_back(i - p.size() + 1);
            }
        }
        return indi;
    }
};
// @lc code=end

