/*
 * @lc app=leetcode id=397 lang=java
 *
 * [397] Integer Replacement
 */

// @lc code=start
class Solution {
    public int integerReplacement(int n) {
        return (int)helper(n);
    }
    
    public long helper(long n){
        if(n == 1) return 0;
        if(n % 2 == 0) return helper(n / 2) + 1;
        else return 1 + Long.min(helper(n + 1), helper(n - 1));
    }
}
// @lc code=end

