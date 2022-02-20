/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        else if(nums.size() == 1) return nums[0];
        else if(nums.size() == 2) return  max(nums[0], nums[1]);
        vector<int> rob1(nums.begin() + 2, nums.end() - 1);
        vector<int> rob1_n(nums.begin() + 1, nums.end());
        return max(DP(rob1) + nums[0], DP(rob1_n));
    }

    int DP(vector<int> &nums){
        if(nums.empty()) return 0;
        else if(nums.size() == 1) return nums[0];
        else if(nums.size() == 2) return  max(nums[0], nums[1]);
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < n; i++){
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }
        return dp[n - 1];
    }
};
// [1,2,3,1, 0, 21,21,2,1,3]
// @lc code=end

