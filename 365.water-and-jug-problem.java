/*
 * @lc app=leetcode id=365 lang=java
 *
 * [365] Water and Jug Problem
 */

// @lc code=start
class Solution {
    public boolean canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        int g = gcd(jug1Capacity, jug2Capacity);
        if(targetCapacity > jug1Capacity + jug2Capacity) return false;
        else if(g != 1 && gcd(g, targetCapacity) == 1) return false;
        return true;
    }
    public int gcd(int a, int b) {
        if (b==0) return a;
        return gcd(b,a%b);
    }
}
// @lc code=end

