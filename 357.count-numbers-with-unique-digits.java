/*
 * @lc app=leetcode id=357 lang=java
 *
 * [357] Count Numbers with Unique Digits
 */

// @lc code=start
class Solution {
    public int countNumbersWithUniqueDigits(int n) {
        int[] res = new int[9];
        int r = 0;
        res[0] = 1;
        res[1] = 9;
        for(int i = 2; i <= n; i++){
            res[i] = res[i - 1] * (11 - i);
        }
        for(int i = 0; i <= n; i++){
            r += res[i];
        }
        return r;
    }
}
// @lc code=end

