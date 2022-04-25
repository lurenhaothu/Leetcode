/*
 * @lc app=leetcode id=383 lang=java
 *
 * [383] Ransom Note
 */

// @lc code=start
class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        //HashMap<Character, Integer> noteMap = new HashMap<>();
        HashMap<Character, Integer> magazineMap = new HashMap<>();
        for(char c : magazine.toCharArray()){
            if(magazineMap.containsKey(c)){
                magazineMap.put(c, magazineMap.get(c) + 1);
            }else{
                magazineMap.put(c, 1);
            }
        }
        for(char c : ransomNote.toCharArray()){
            if(magazineMap.containsKey(c) && magazineMap.get(c) >= 1){
                magazineMap.put(c, magazineMap.get(c) - 1);
            }else{
                return false;
            }
        }
        return true;
    }
}
// @lc code=end

