/*
 * @lc app=leetcode id=387 lang=java
 *
 * [387] First Unique Character in a String
 */

// @lc code=start
class Solution {
    public int firstUniqChar(String s) {
        LinkedHashMap<Character, Integer> res = new LinkedHashMap<>();
        HashSet<Character> repeated = new HashSet<Character>();
        var arr = s.toCharArray();
        for(int i = 0; i < arr.length; i++){
            if(repeated.contains(arr[i])) continue;
            if(res.containsKey(arr[i])){
                res.remove(arr[i]);
                repeated.add(arr[i]);
            }else{
                res.put(arr[i],i);
            }
        }
        var itr = res.keySet().iterator();
        if(itr.hasNext()){
            return res.get(itr.next());
        }else{
            return -1;
        }
    }
}
// @lc code=end

