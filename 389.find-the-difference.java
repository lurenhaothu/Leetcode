/*
 * @lc app=leetcode id=389 lang=java
 *
 * [389] Find the Difference
 */

// @lc code=start
class Solution {
    public char findTheDifference(String s, String t) {
        HashMap<Character, Integer> dict = new HashMap<>();
        for(char c : t.toCharArray()){
            if(dict.containsKey(c)) dict.put(c, dict.get(c) + 1);
            else dict.put(c, 1);
        }
        for(char c : s.toCharArray()){
            if(dict.get(c) > 1) dict.put(c, dict.get(c) - 1);
            else dict.remove(c);
        }
        return dict.keySet().iterator().next();
    }
}
// @lc code=end

