/*
 * @lc app=leetcode id=342 lang=cpp
 *
 * [342] Power of Four
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(__builtin_ffs(n) % 2 != 1) return false;
        //ffs, find first set
        //clz, count leading zero
        else if((n & (-n)) != n) return false;
        else return true;
    }
};
// @lc code=end

