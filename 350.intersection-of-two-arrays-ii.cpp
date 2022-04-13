/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_multiset<int> dict(nums1.begin(), nums1.end());
        vector<int> res;
        for(auto i : nums2){
            if(dict.find(i) != dict.end()) {dict.erase(dict.find(i)); res.push_back(i);}
        }
        return res;
    }
};
// @lc code=end

