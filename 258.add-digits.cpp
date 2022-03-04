/*
 * @lc app=leetcode id=258 lang=cpp
 *
 * [258] Add Digits
 */

// @lc code=start
class Solution {
public:
    int addDigits(int num) {
        while(num >= 10){
            num = helper(num);
        }
        return num;
    }
    int helper(int num){
        int r = 0;
        while(num != 0){
            r += num % 10;
            num /= 10;
        }
        return r;
    }
};
// @lc code=end

