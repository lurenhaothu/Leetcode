/*
 * @lc app=leetcode id=324 lang=cpp
 *
 * [324] Wiggle Sort II
 */

// @lc code=start
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp = nums;
        int offset = nums.size() / 2 + nums.size() % 2;
        reverse(temp.begin(), temp.begin() + offset);
        reverse(temp.begin() + offset, temp.end());
        for(int i = 0; 2 * i < nums.size(); i++){
            nums[2 * i] = temp[i];
            if(2 * i + 1 < nums.size()) nums[2 * i + 1] = temp[i + offset];
        }
        return;
    }
};
// @lc code=end

