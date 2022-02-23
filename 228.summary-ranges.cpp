/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 */

// @lc code=start
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(nums.empty()) return res;
        int start = nums[0], end = nums[0];
        for(auto i : nums){
            if(i == end) continue;
            if(i == end + 1){
                end++;
                continue;
            }else if(i > end + 1){
                if(start == end) res.push_back(to_string(start));
                else res.push_back(to_string(start) + "->" + to_string(end));
                start = i;
                end = i;
            }
        }
        if(start == end) res.push_back(to_string(start));
        else res.push_back(to_string(start) + "->" + to_string(end));
        return res;
    }
};
// @lc code=end

