#
# @lc app=leetcode id=488 lang=python3
#
# [488] Zuma Game
#

# @lc code=start
class Solution:
    def findMinStep(self, board: str, hand: str) -> int:
        def refresh(b):
            count = 0
            last = '#'
            for i in range(len(b)):
                c = b[i]
                if c == last:
                    count += 1
                else:
                    if count >= 3:
                        return True, b[:i - count] + b[i:]
                    count = 1
                    last = c
            if count >= 3:
                return True, b[: -count]
            return False, b
        #dic = {}
        def DFS(b, h, count, opt):
            #print(b + ' ' + h)
            #if b in dic:
            #    return dic[b]
            if len(b) == 0:
                opt = min(opt, count)
                return count
            if len(h) == 0:
                return -1
            last = '#'
            if count >= opt:
                return -1
            for c in "RYBGW":
                t = b.count(c)
                if t != 0 and t + h.count(c) < 3:
                    return -1
            for j in range(len(h)):
                c = h[j]
                if c == last:
                    continue
                else:
                    last = c
                for i in range(len(b) + 1):
                    if i >= 1 and c == b[i - 1]:
                        continue
                    if i < len(b) and b[i] == c:
                        pass
                    elif len(h) > 1 and i > 0 and i < len(b) and b[i] == b[i - 1]:
                        pass
                    else:
                        continue
                    newb = b[:i] + c + b[i:]
                    temp, newb = refresh(newb)
                    while temp:
                        temp, newb = refresh(newb)
                    r = DFS(newb, h[:j] + h[j + 1:], count + 1, opt)
                    if r != -1:
                        opt = min(opt, r)
            #dic[b] = opt
            return opt
        n = len(hand)
        hand = ''.join(sorted(hand))
        res = DFS(board, hand, 0, n + 1)
        if res == n + 1:
            return -1
        else:
            return res
# @lc code=end

