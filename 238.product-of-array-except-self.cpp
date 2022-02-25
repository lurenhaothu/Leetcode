/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        int r = 1;
        for(int i = 0; i < nums.size() - 1; i++){
            r *= nums[i];
            res[i + 1] = r;
        }
        r = 1;
        for(int i = nums.size() - 1; i > 0; i--){
            r *= nums[i];
            res[i - 1] *= r;
        }
        return res;
    }
};
// @lc code=end

