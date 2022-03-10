/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int ptr1 = 0, ptr2 = 0;
        int n = nums.size();
        while(ptr1 < n){
            if(nums[ptr1] == 0) ptr1++;
            else{
                nums[ptr2] = nums[ptr1];
                ptr1++;
                ptr2++;
            }
        }
        while(ptr2 < n) {nums[ptr2] = 0; ptr2++;}
        return;
    }
};
// @lc code=end

