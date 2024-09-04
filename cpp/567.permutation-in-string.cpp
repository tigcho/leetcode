/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // map for storing the frequency of characters in s1 and s2
        map<char, int> m1, m2;

        // iterate through s1 and store the frequency of characters in m1
        for (char c : s1) m1[c]++;

        int n = s1.size();

        for (int i = 0; i < s2.size(); i++) {
            // store the frequency of characters in m2
            m2[s2[i]]++;

            // if window is bigger than string size, remove the first character 
            if (i >= n) {
                // decrement freq of char that is leaving the map
                if (--m2[s2[i - n]] == 0) m2.erase(s2[i - n]);
            }

            // compare the frequency of characters in m1 and m2
            if (m1 == m2) return true;
        }
        // no permutation found
        return false;
    }
};
// @lc code=end

