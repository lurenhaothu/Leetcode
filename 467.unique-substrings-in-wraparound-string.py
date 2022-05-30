#
# @lc app=leetcode id=467 lang=python3
#
# [467] Unique Substrings in Wraparound String
#

# @lc code=start
class Solution:
    def findSubstringInWraproundString(self, p: str) -> int:
        def helper(c):
            return ord(c) - ord('a')
        cur = 1
        dp = [0] * 26
        dp[helper(p[0])] = 1
        for i in range(1, len(p)):
            if helper(p[i]) == (helper(p[i - 1]) + 1 ) % 26:
                cur += 1
                dp[helper(p[i])] = max(cur, dp[helper(p[i])])
                continue
            else:
                cur = 1
                dp[helper(p[i])] = max(cur, dp[helper(p[i])])
        #print(dp)
        res = 0
        for i in dp:
            res += i
        return res
# @lc code=end

