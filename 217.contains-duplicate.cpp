/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> dic;
        for(auto i : nums){
            if(dic.find(i) == dic.end()) dic.insert(i);
            else return true;
        }
        return false;
    }
};
// @lc code=end

