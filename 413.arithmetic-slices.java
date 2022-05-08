/*
 * @lc app=leetcode id=413 lang=java
 *
 * [413] Arithmetic Slices
 */

// @lc code=start
class Solution {
    public int numberOfArithmeticSlices(int[] nums) {
        int n = nums.length;
        int dif[] = new int[n - 1];
        for(int i = 0; i < n - 1; i++){
            dif[i] = nums[i + 1] - nums[i];
        }
        ArrayList<Integer> lens = new ArrayList<>();
        int curLen = 0;
        int curNum = 10000;
        for(int i : dif){
            if(curNum != i){
                if(curLen >= 2){
                    lens.add(curLen);
                }
                curLen = 1;
                curNum = i;
            }else{
                curLen++;
            }
        }
        if(curLen >= 2) lens.add(curLen);
        int res = 0;
        for(int i : lens){
            res += (i - 1) * i / 2;
        }
        return res;
    }
}
// @lc code=end

