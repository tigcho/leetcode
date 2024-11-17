/*
 * @lc app=leetcode id=862 lang=cpp
 *
 * [862] Shortest Subarray with Sum at Least K
 */

// @lc code=start
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> P(n+1, 0); // avoid overflow

        for (int i = 0; i < n; i++) {
            P[i+1] = P[i] + nums[i]; // P[i+1] is the sum of the first i+1 elements of nums
        }

        deque<int> dq;
        int res = n+1; // ensure that any valid subarr length found will be smaller

        for (int i = 0; i < n+1; i++) {
            while (!dq.empty() && P[i] - P[dq.front()] >= k) {
                res = min(res, i - dq.front());
                dq.pop_front();
            }

            while (!dq.empty() && P[i] <= P[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        // if res is still n+1, it means no valid subarr found, so return -1
        return res == n+1 ? -1 : res;
    }
};
// @lc code=end

