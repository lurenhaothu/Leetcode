/*
 * @lc app=leetcode id=396 lang=java
 *
 * [396] Rotate Function
 */

// @lc code=start
class Solution {
    public int maxRotateFunction(int[] nums) {
        int n = nums.length;
        int r = 0;
        int allSum = 0;
        for(int j = 0; j < n; j++){
            r += j * nums[j];
            allSum += nums[j];
        }
        int res = r;
        for(int i = 1; i < n; i++){
            r = r - n * nums[n - i] + allSum;
            res = Integer.max(r, res);
        }
        return res;
    }
}
// @lc code=end

