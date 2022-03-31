/*
 * @lc app=leetcode id=312 lang=cpp
 *
 * [312] Burst Balloons
 */

// @lc code=start
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size(); //real length is n - 2
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i + 2 < n; i++){
            dp[i][i + 2] = nums[i] * nums[i + 1] * nums[i + 2];
        }
        for(int l = 4; l <= n; l++){
            for(int i = 0; i + l - 1 < n; i++){
                for(int j = i + 1; j <= i + l - 2; j++){
                    int r = nums[j] * nums[i] * nums[i + l - 1];
                    r += dp[i][j] + dp[j][i + l - 1];
                    dp[i][i + l - 1] = max(r, dp[i][i + l - 1]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
// @lc code=end

