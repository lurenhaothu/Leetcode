#
# @lc app=leetcode id=485 lang=python3
#
# [485] Max Consecutive Ones
#

# @lc code=start
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        res = 0
        count = 0
        for i in nums:
            if i == 0:
                count = 0
            else:
                count += 1
                res = max(res, count)
        return res
# @lc code=end

