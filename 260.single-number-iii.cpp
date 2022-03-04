/*
 * @lc app=leetcode id=260 lang=cpp
 *
 * [260] Single Number III
 */

// @lc code=start
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long mask = 0;
        for(auto i : nums) mask ^= i;
        long long dif = mask & (-mask);
        long long newmask = 0;
        for(auto i : nums){
            if(dif & i) newmask ^= i;
        }
        return {(int)newmask, (int)(mask ^ newmask)};
    }
};
// @lc code=end

