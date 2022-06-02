#
# @lc app=leetcode id=481 lang=python3
#
# [481] Magical String
#

# @lc code=start
class Solution:
    def magicalString(self, n: int) -> int:
        mag = [1, 2, 2]
        index = 2
        res = 1
        while len(mag) < n:
            if mag[index] == 2:
                if mag[-1] == 1:
                    mag.append(2)
                    mag.append(2)
                else:
                    mag.append(1)
                    if len(mag) <= n:
                        res += 1
                    mag.append(1)
                    if len(mag) <= n:
                        res += 1
            else:
                if mag[-1] == 1:
                    mag.append(2)
                else:
                    mag.append(1)
                    if len(mag) <= n:
                        res += 1
            index += 1
        #print(mag)
        return res
# @lc code=end

