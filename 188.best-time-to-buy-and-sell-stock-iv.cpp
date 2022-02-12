/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 */

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n <= 1) return 0;
        vector<vector<int>> low(n, vector<int>(n, 0));
        vector<vector<int>> pro(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                low[i][j] = i == j ? prices[i] : min(prices[j], low[i][j - 1]);
                pro[i][j] = i == j ? 0 : max(pro[i][j - 1], prices[j] - low[i][j]);
            }
        }
        /*for(auto i : pro){
            for(auto j : i) cout<<j;
            cout<<endl;
        }*/
        vector<vector<int>> dp(k + 1, vector<int>(n, 0));
        for(int i = 1; i <= k; i++){
            for(int j = 0; j < n; j++){
                int maxn = max(dp[i - 1][j], pro[0][j]);
                for(int p = 0; p < j; p++){
                    maxn = max(maxn, dp[i - 1][p] + pro[p + 1][j]);
                    //cout<<pro[p + 1][j];
                }
                dp[i][j] = maxn;
            }
        }
        /*for(auto i : dp){
            for(auto j : i) cout<<j;
            cout<<endl;
        }*/
        return dp[k][n - 1];
    }
};
// @lc code=end

// 2\n[3,2,6,5,0,3]

