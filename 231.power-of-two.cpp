/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        int ones = 0;
        for(int i = 0; i < 31; i++){
            if(n >> i & 1 == 1) ones++;
        }
        return ones == 1;
    }
};
// @lc code=end

