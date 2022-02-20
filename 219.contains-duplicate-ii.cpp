/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> dic;
        for(int i = 0; i < nums.size(); i++){
            if(dic.find(nums[i]) == dic.end() || i - dic[nums[i]] > k){
                dic[nums[i]] = i;
            }else return true;
        }
        return false;
    }
};
// @lc code=end

