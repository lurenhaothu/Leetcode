/*
 * @lc app=leetcode id=405 lang=java
 *
 * [405] Convert a Number to Hexadecimal
 */

// @lc code=start
class Solution {
    public String toHex(int num) {
        char res[] = new char[8];
        for(int i = 0; i < 8; i++){
            res[i] = toHexChar((num >> (28 - 4 * i)) & 15);
        }
        int start = 0;
        while(res[start] == '0' && start != 7) start++;
        return new String(res).substring(start, 8);
    }
    private char toHexChar(int i){
        if(i < 10) return (char)('0' + i);
        else return (char)('a' + i - 10);
    }
}
// @lc code=end

