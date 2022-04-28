/*
 * @lc app=leetcode id=395 lang=java
 *
 * [395] Longest Substring with At Least K Repeating Characters
 */

// @lc code=start
class Solution {
    public int longestSubstring(String s, int k) {
        HashMap<Character, Integer> map = new HashMap<>();
        for(char c : s.toCharArray()){
            if(map.containsKey(c)) map.put(c, map.get(c) + 1);
            else map.put(c, 1);
        }
        int unique = map.size();
        int res = 0;
        int n = s.length();
        for(int i = 1; i <= unique; i++){
            map.clear();
            int start = 0;
            int end = 0;
            map.put(s.charAt(0), 1);
            
            while(start <= end && end < n){
                //System.out.println(s.substring(start, end + 1));
                boolean valid = true;
                for(char ch : map.keySet()){
                    if(map.get(ch) >= k) continue;
                    else{
                        valid = false;
                        break;
                    }
                }
                if(valid) res = Integer.max(res, end - start + 1);
                if(map.size() <= i && end + 1 < n){
                    end++;
                    char c = s.charAt(end);
                    if(map.containsKey(c)) map.put(c, map.get(c) + 1);
                    else map.put(c, 1);
                }else if(map.size() > i && start + 1 < n){
                    
                    char c = s.charAt(start);
                    start++;
                    if(map.get(c) != 1) map.put(c, map.get(c) - 1);
                    else map.remove(c);
                }else{
                    break;
                }
            }
        }
        return res;
    }
}
// @lc code=end

