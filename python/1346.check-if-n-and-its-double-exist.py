#
# @lc app=leetcode id=1346 lang=python3
#
# [1346] Check If N and Its Double Exist
#

# @lc code=start
class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        checked = set()
        for num in arr:
            if 2 * num in checked or (num % 2 == 0 and num // 2 in checked):
                return True
            checked.add(num)
        return False
# @lc code=end

