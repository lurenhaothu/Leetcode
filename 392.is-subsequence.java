/*
 * @lc app=leetcode id=392 lang=java
 *
 * [392] Is Subsequence
 */

// @lc code=start
class Solution {
    public boolean isSubsequence(String s, String t) {
        int ptr = 0;
        for(char c : s.toCharArray()){
            boolean found = false;
            while(ptr < t.length()){
                if(t.charAt(ptr) == c){
                    ptr++;
                    found = true;
                    break;
                }else{
                    ptr++;
                }
            }
            if(!found) return false;
        }
        return true;
    }
}
// @lc code=end

