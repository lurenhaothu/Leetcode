/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> dict(nums1.begin(), nums1.end());
        vector<int> res;
        for(auto i : nums2){
            if(dict.find(i) != dict.end()) {dict.erase(dict.find(i)); res.push_back(i);}
        }
        return res;
    }
};
// @lc code=end

