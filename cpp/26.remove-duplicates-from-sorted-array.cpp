/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // keep track of position of the next unique element
        int j = 1;

        // iterate from 1, because 0 is already a unique element
        for (int i = 1; i < nums.size(); i++) {

            // if current is not equal to previous, then it is unique
            if (nums[i] != nums[i - 1]) {

                // copy the unique element to the next position
                nums[j++] = nums[i];
            }
        }

        // return length of array with unique elements
        return j;
    }
};
// @lc code=end

