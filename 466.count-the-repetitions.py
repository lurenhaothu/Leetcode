#
# @lc app=leetcode id=466 lang=python3
#
# [466] Count The Repetitions
#

# @lc code=start
class Solution:
    def getMaxRepetitions(self, s1: str, n1: int, s2: str, n2: int) -> int:
        for c in s2:
            if not c in s1:
                return 0
        l1 = len(s1)
        l2 = len(s2)
        count = [0]
        remain = [0]
        remainDict = {}
        remainDict[0] = 0
        curCount = 0
        curRemain = 0
        index1 = 0
        index2 = 0
        while True:
            if s1[index1] == s2[index2]:
                index2 += 1
                if index2 == l2:
                    index2 = 0
                    curCount += 1
                    curRemain = -1
            index1 += 1
            curRemain += 1
            if index1 == l1:
                index1 = 0
                count.append(curCount)
                remain.append(curRemain)
                if not curRemain in remainDict:
                    remainDict[curRemain] = len(count) - 1
                else:
                    break
        #print(count)
        #print(remain)
        if n1 < len(count):
            return count[n1] // n2
        lastRemainIndex = remainDict[remain[len(count) - 1]]
        T = len(count) - 1 - lastRemainIndex
        Tcount = count[len(count) - 1] - count[len(count) -1 - T]
        nLoop = (n1 - len(count) + 1) // T
        nOffset = (n1 - len(count) + 1) % T
        res = count[len(count) - 1] + nLoop * Tcount + count[lastRemainIndex + nOffset] - count[lastRemainIndex]
        return res // n2
                
# @lc code=end

