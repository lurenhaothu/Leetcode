#
# @lc app=leetcode id=476 lang=python3
#
# [476] Number Complement
#

# @lc code=start
class Solution:
    def findComplement(self, num: int) -> int:
        binNum = bin(num)[2:]
        res = ''
        for i in binNum:
            if i == '0':
                res += '1'
            else:
                res += '0'
        return int(res, 2)# @lc code=end

