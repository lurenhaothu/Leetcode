/*
 * @lc app=leetcode id=390 lang=java
 *
 * [390] Elimination Game
 */

// @lc code=start
class Solution {
    public int lastRemaining(int n) {
        if(n == 1) return 1;
        else if(n == 2) return 2;
        else if(n == 3) return 2;
        else if(n == 4) return 2;
        n = n / 2;
        if(n % 2 == 0){
            return 2 * (lastRemaining(n / 2) * 2 - 1);
        }else{
            return 2 * (lastRemaining(n/ 2) * 2);
        }
    }
}
// @lc code=end

