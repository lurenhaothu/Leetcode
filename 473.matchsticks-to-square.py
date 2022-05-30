#
# @lc app=leetcode id=473 lang=python3
#
# [473] Matchsticks to Square
#

# @lc code=start
class Solution:
    def makesquare(self, matchsticks: List[int]) -> bool:
        matchsticks.sort(reverse = True)
        sumLen = 0
        for i in matchsticks: sumLen += i
        if sumLen % 4 != 0:
            return False
        edge = sumLen // 4
        count = 0
        curLen = 0
        lastTry = -1
        candidate = '1' * len(matchsticks)
        def DFS(c, l, last, cand):
            for i in range(last + 1, len(cand)):
                if cand[i] == '0':
                    continue
                elif l + matchsticks[i] > edge:
                    continue
                elif cand[i] == '1' and i > 0 and cand[i - 1] == '1' and matchsticks[i] == matchsticks[i - 1]:
                    continue
                newl = l + matchsticks[i]
                newc = c
                newlast = i
                if newl == edge:
                    newc += 1
                    newl = 0
                    newlast = -1
                newcand = cand[0:i] + '0' + cand[i + 1:]
                if newc == 3:
                    return True
                if DFS(newc, newl, newlast, newcand):
                    return True
            return False
        return DFS(count, curLen, lastTry, candidate)
        
# @lc code=end

