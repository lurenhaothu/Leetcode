/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int maxl = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '0') continue;
                int up = i == 0 ? 0 : dp[i - 1][j];
                int lft = j == 0 ? 0 : dp[i][j - 1];
                int ul = (i != 0 && j != 0) ? dp[i - 1][j - 1] : 0;
                dp[i][j] = min(min(up, lft), ul) + 1;
                maxl = max(maxl, dp[i][j]);
            }
        }
        return maxl * maxl;
    }
};
// @lc code=end

