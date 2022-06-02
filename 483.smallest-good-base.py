#
# @lc app=leetcode id=483 lang=python3
#
# [483] Smallest Good Base
#

# @lc code=start
class Solution:
    def smallestGoodBase(self, n: str) -> str:
        n = int(n)
        bits = len(bin(n)) - 2
        def cal(bitNum, base):
            temp = 1
            res = 0
            for i in range(bitNum):
                res += temp
                temp *= base
            return res
        def helper(n, bitNum):
            start = 1
            end = n >> (bitNum - 2)
            while start < end:
                pivot = (start + end) // 2
                r = cal(bitNum, pivot)
                if r == n:
                    return pivot
                elif r > n:
                    end = pivot - 1
                elif r < n:
                    start = pivot + 1
            if start == end and cal(bitNum, start) == n:
                return start
            else:
                return None
                
        for bitNum in range(bits, 1, -1):
            res = helper(n, bitNum)
            if res == None:
                continue
            else:
                #print(bitNum)
                return str(res)
# @lc code=end

