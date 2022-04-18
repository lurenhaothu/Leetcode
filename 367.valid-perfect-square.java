/*
 * @lc app=leetcode id=367 lang=java
 *
 * [367] Valid Perfect Square
 */

// @lc code=start
class Solution {
    public boolean isPerfectSquare(int num) {
        int start = 1;
        int end = num / 2;
        int pivot;
        while(start < end){
            pivot = (start + end) / 2;
            long square = (long)pivot * pivot;
            if(square > num){
                end = pivot - 1;
            }else if(square < num){
                start = pivot + 1;
            }else return true;
            //System.out.println(square);
        }
        
        if(start * start == num) return true;
        else return false;
    }
}
// @lc code=end

