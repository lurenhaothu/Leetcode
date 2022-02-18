/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0, sum = nums[0], minl = n + 1;
        while(r < n){
            if(sum >= target){
                minl = min(minl, r - l + 1);
                if(r == l){
                    r++;
                    if(r >= n) break;
                    sum += nums[r];
                }
                else{
                    sum -= nums[l];
                    l++;
                }
            }else{
                r++;
                if(r >= n) break;
                sum += nums[r];
            }
        }
        if(minl == n + 1) return 0;
        else return minl;
    }
};
// @lc code=end

