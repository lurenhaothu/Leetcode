#
# @lc app=leetcode id=477 lang=python3
#
# [477] Total Hamming Distance
#

# @lc code=start
class Solution:
    def totalHammingDistance(self, nums: List[int]) -> int:
        ones = [0] * 31
        zeros = [0] * 31
        for i in nums:
            for j in range(31):
                if ((i >> j) & 1) != 0:
                    ones[j] += 1
                else:
                    zeros[j] += 1
        res = 0
        for j in range(31):
            res += ones[j] * zeros[j]
        return res
# @lc code=end

