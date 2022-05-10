/*
 * @lc app=leetcode id=423 lang=java
 *
 * [423] Reconstruct Original Digits from English
 */

// @lc code=start
class Solution {
    public String originalDigits(String s) {
        int[] dict = new int[26];
        int[] res = new int[10];
        for(char c : s.toCharArray()){
            dict[(int)(c - 'a')]++;
        }
        helper(0, 'z', "zero", res, dict);
        helper(6, 'x', "six", res, dict);
        helper(2, 'w', "two", res, dict);
        helper(8, 'g', "eight", res, dict);
        helper(7, 's', "seven", res, dict);
        helper(5, 'v', "five", res, dict);
        helper(4, 'f', "four", res, dict);
        helper(1, 'o', "one", res, dict);
        helper(9, 'i', "nine", res, dict);
        helper(3, 'h', "three", res, dict);
        String resStr = "";
        for(int i = 0; i <= 9; i++){
            resStr += Integer.toString(i).repeat(res[i]);
        }
        return resStr;
    }
    
    private void helper(int num, char c, String name, int[] res, int[] dict){
        res[num] = dict[(int)(c - 'a')];
        for(char ch : name.toCharArray()){
            dict[(int)(ch - 'a')] -= res[num];
        }
    }
}
// @lc code=end

