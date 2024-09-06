/*
 * @lc app=leetcode id=828 lang=cpp
 *
 * [828] Count Unique Characters of All Substrings of a Given String
 */

// @lc code=start
class Solution {
public:
    int uniqueLetterString(string s) {
        // 0 implies that the character has appeared at the start of the string
        // -1 means that the character has not been seen yet
        vector<int> lastPosition(26, -1);
        vector<int> secondLastPosition(26, -1);
        int uniqueCount = 0;


        // example: "ABA"

        // i = 0, s[i] = 'A'
        // charIndex = 'A' - 'A' = 0
        // uniqueCount += (0 - (-1)) * ((-1) - (-1)) = 0
        // Update positions:
        // secondLastPosition[0] = -1
        // lastPosition[0] = 0

        // i = 1, s[i] = 'B'
        // charIndex = 'B' - 'A' = 1
        // uniqueCount += (1 - (-1)) * ((-1) - (-1)) = 0
        // Update positions:
        // secondLastPosition[1] = -1
        // lastPosition[1] = 1

        // i = 2, s[i] = 'A'
        // charIndex = 'A' - 'A' = 0
        // uniqueCount += (2 - 0) * (0 - (-1)) = 2 * 1 = 2
        // Update positions:
        // secondLastPosition[0] = 0
        // lastPosition[0] = 2
        for (int i = 0; i < s.size(); i++) {
            int charIndex = s[i] - 'A';
            uniqueCount += (i - lastPosition[charIndex]) * (lastPosition[charIndex] - secondLastPosition[charIndex]);
            secondLastPosition[charIndex] = lastPosition[charIndex];
            lastPosition[charIndex] = i;
        }

        // Calculate the contribution of characters for the remaining substrings
        for (int i = 0; i < 26; i++) {
            uniqueCount += (s.size() - lastPosition[i]) * (lastPosition[i] - secondLastPosition[i]);
        }

        return uniqueCount;
    }

    int countUniqueChars(const string &s) {
        unordered_set<char> uniqueChars;

        for (char c : s) {
            uniqueChars.insert(c);
        }

        return uniqueChars.size();
    }
};
// @lc code=end

