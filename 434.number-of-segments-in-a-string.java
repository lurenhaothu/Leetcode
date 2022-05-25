/*
 * @lc app=leetcode id=434 lang=java
 *
 * [434] Number of Segments in a String
 */

// @lc code=start
class Solution {
    public int countSegments(String s) {
        boolean inSeg = false;
        int res = 0;
        for(char c : s.toCharArray()){
            if(!inSeg){
                if(c != ' '){
                    res++;
                    inSeg = true;
                }
            }else{
                if(c == ' '){
                    inSeg = false;
                }
            }
        }
        return res;
    }
}
// @lc code=end

