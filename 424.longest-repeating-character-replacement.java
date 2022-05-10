/*
 * @lc app=leetcode id=424 lang=java
 *
 * [424] Longest Repeating Character Replacement
 */

// @lc code=start
class Solution {
    public int characterReplacement(String s, int k) {
        int start = k;
        int end = s.length();
        int pivot;
        while(start < end){
            pivot = (start + end) / 2 + (start + end) % 2;
            int r = helper(s, pivot);
            if(r > k){
                end = pivot - 1;
            }else if(r <= k){
                start = pivot;
            }
            //System.out.println(Integer.toString(start) + ' ' + Integer.toString(end));
        }
        return start;
    }
    private int helper(String s, int len){
        int n = s.length();
        int[] dict = new int[26];
        for(int i = 0; i < len; i++){
            dict[(int)(s.charAt(i) - 'A')]++;
        }
        int res = len;
        for(int count : dict) res = Integer.min(res, len - count);
        for(int end = len; end < n; end++){
            int start = end - len;
            dict[(int)(s.charAt(start) - 'A')]--;
            dict[(int)(s.charAt(end) - 'A')]++;
            res = Integer.min(res, len - dict[(int)(s.charAt(end) - 'A')]);
        }
        return res;
    }
}
// @lc code=end

