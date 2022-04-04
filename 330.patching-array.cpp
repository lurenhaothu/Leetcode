/*
 * @lc app=leetcode id=330 lang=cpp
 *
 * [330] Patching Array
 */

// @lc code=start
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int res = 0;
        long long reach = 0;
        for(auto i : nums){
            while(reach + 1 < i && reach < n){
                res++;
                reach = 2 * reach + 1;
            }
            reach += i;
            if(reach >= n) return res;
            else continue;
        }
        while(reach < n){
            res++;
            reach = 2 * reach + 1;
        }
        return res;
    }
};
// @lc code=end

