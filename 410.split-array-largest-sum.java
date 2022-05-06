/*
 * @lc app=leetcode id=410 lang=java
 *
 * [410] Split Array Largest Sum
 */

// @lc code=start
class Solution {
    public int splitArray(int[] nums, int m) {
        int start = 0, end = 0;
        for(int i : nums) end += i;
        int pivot;
        while(start < end){
            //System.out.println(Integer.toString(start) + ' ' + Integer.toString(end));
            pivot = (start + end) / 2;
            if(!helper(nums, pivot, m)){
                start = pivot + 1;
            }else{
                end = pivot;
            }
        }
        return start;
    }
    public boolean helper(int[] nums, int k, int m){
        int n = 0;
        int sum = 0;
        for(int i : nums){
            if(i > k) return false;
            if(sum + i > k){
                n++;
                sum = 0;
            }
            sum += i;
        }
        //System.out.println(Integer.toString(k) + ' ' + Integer.toString(n + 1));
        return n + 1 <= m;
    }
}
// @lc code=end

