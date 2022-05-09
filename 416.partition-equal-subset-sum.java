/*
 * @lc app=leetcode id=416 lang=java
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution {
    public boolean canPartition(int[] nums) {
        int n = nums.length;
        int sum = 0;
        for(int i : nums) sum += i;
        if(sum % 2 == 1) return false;
        sum /= 2;
        boolean dp[][] = new boolean[n][sum + 1];
        for(int i = 0; i < n; i++) dp[i][0] = true;
        if(nums[0] <= sum){
            dp[0][nums[0]] = true;
        }
        for(int i = 1; i < n; i++){
            for(int j = 0; j <= sum; j++){
                if(dp[i - 1][j]){
                    dp[i][j] = true;
                    if(j + nums[i] <= sum)dp[i][j + nums[i]] = true;
                }
            }
        }
        return dp[n - 1][sum];
    }
}
// @lc code=end

