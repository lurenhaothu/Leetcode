#
# @lc app=leetcode id=474 lang=python3
#
# [474] Ones and Zeroes
#

# @lc code=start
class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        counts = [[i.count('0'), i.count('1')] for i in strs]
        #print(counts)
        l = len(counts)
        dp = [[ [0 for _ in range(n + 1)] for _ in range(m + 1)] for _ in range(l + 1)]
        for i in range(1, l + 1):
            for j in range(0, m + 1):
                for k in range(0, n + 1):
                    if j >= counts[i - 1][0] and k >= counts[i - 1][1]:
                        dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - counts[i - 1][0]][k - counts[i - 1][1]] + 1)
                    else:
                        dp[i][j][k] = dp[i - 1][j][k]
        #print(dp)
        return dp[l][m][n]
# @lc code=end

