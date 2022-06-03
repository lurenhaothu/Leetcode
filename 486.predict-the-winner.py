#
# @lc app=leetcode id=486 lang=python3
#
# [486] Predict the Winner
#

# @lc code=start
class Solution:
    def PredictTheWinner(self, nums: List[int]) -> bool:
        n = len(nums)
        dp = [[0 for _ in range(n)] for _ in range(n)]
        for i in range(n):
            dp[i][i] = nums[i]
        for l in range(2, n + 1):
            for i in range(n - l + 1):
                dp[i][i + l - 1] = max(nums[i] - dp[i + 1][i + l - 1], nums[i + l - 1] - dp[i][i + l - 2])
        #print(dp)
        return dp[0][n - 1] >= 0
# @lc code=end

