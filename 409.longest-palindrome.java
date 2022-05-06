/*
 * @lc app=leetcode id=409 lang=java
 *
 * [409] Longest Palindrome
 */

// @lc code=start
class Solution {
    public int longestPalindrome(String s) {
        HashMap<Character, Integer> dict = new HashMap<>();
        for(char c : s.toCharArray()){
            if(!dict.containsKey(c)) dict.put(c, 1);
            else dict.put(c, dict.get(c) + 1);
        }
        boolean odd = false;
        int res = 0;
        for(var entry : dict.entrySet()){
            if(entry.getValue() % 2 == 1){
                odd = true;
                res += entry.getValue() - 1;
            }else{
                res += entry.getValue();
            }
        }
        
        return res + (odd?1:0);
    }
}
// @lc code=end

