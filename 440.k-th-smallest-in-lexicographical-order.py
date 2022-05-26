#
# @lc app=leetcode id=440 lang=python3
#
# [440] K-th Smallest in Lexicographical Order
#

# @lc code=start
class Solution:
    def findKthNumber(self, n: int, k: int) -> int:
        totalN = n
        res = ''
        l = len(str(n))
        count = 0
        for i in range(l):
            list = self.helper(res, n, totalN)
            for j in range(-1, 10):
                count += list[j]
                if count >= k:
                    if j == -1: return int(res)
                    count -= list[j]
                    totalN = list[j]
                    res += str(j)
                    if list[j] == 1: return int(res)
                    break
        return res
        
        
    def helper(self, head, n, totalN):
        #print(head)
        res = {}
        if(head == ''): res[-1] = 0
        else: res[-1] = 1
        l = len(head)
        digit = int(str(n)[l]) 
        countSum = res[-1]
        for i in range(10):
            if l == 0 and i == 0:
                res[0] = 0
                continue
            if i == digit:
                continue
            newNum = head + str(i)
            if int(newNum) > n:
                res[i] = 0
            else:
                j = 1
                while int(newNum + ('9' * j)) < n:
                    j += 1
                if j > 0:res[i] = int('1' * j)
                else: res[i] = 1
            countSum += res[i]
        res[digit] = totalN - countSum
        #print(res)
        return res
        
        
# @lc code=end

