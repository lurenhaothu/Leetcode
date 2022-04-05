/*
 * @lc app=leetcode id=334 lang=cpp
 *
 * [334] Increasing Triplet Subsequence
 */

// @lc code=start
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<bool> larger(n, false), smaller(n, false);
        int maxnum = nums.back(), minnum = nums[0];
        for(int i = n - 2; i >= 1; i--){
            if(nums[i] < maxnum) larger[i] = true;
            maxnum = max(maxnum, nums[i]);
        }
        for(int i = 1; i <= n - 2; i++){
            if(nums[i] > minnum) smaller[i] = true;
            minnum = min(minnum, nums[i]);
            if(smaller[i] && larger[i]) return true;
        }
        return false;
    }
};
// @lc code=end

