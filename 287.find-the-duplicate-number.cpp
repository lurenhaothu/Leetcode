/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size() - 1;
        int start = 1, end = n, pivot;
        while(start < end){
            pivot = (start + end) / 2;
            int k = 0;
            for(auto i : nums) if(i >= start && i <= pivot) k++;
            if(k > pivot - start + 1) end = pivot;
            else start = pivot + 1;
        }
        return start;
    }
};
// @lc code=end

