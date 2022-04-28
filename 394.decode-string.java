/*
 * @lc app=leetcode id=394 lang=java
 *
 * [394] Decode String
 */

// @lc code=start
class Solution {
    public String decodeString(String s) {
        int ptr = 0;
        int n = s.length();
        String res = "";
        while(ptr < n){
            int oldptr = ptr;
            while(ptr < n && s.charAt(ptr) >= 'a' && s.charAt(ptr) <= 'z') ptr++;
            if(oldptr != ptr) {res += s.substring(oldptr, ptr);continue;}
            while(ptr < n && s.charAt(ptr) >= '0' && s.charAt(ptr) <= '9') ptr++;
            int num = Integer.parseInt(s.substring(oldptr, ptr));
            int brack = 1;
            ptr++;
            oldptr = ptr;
            while(ptr < n && brack != 0){
                if(s.charAt(ptr) == '[') brack++;
                if(s.charAt(ptr) == ']') brack--;
                ptr++;
            }
            String mono = decodeString(s.substring(oldptr, ptr - 1));
            //System.out.println(mono);
            for(int i = 0; i < num; i++) res += mono;
        }
        return res;
    }
}
// @lc code=end

