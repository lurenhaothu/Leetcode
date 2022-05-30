/*
 * @lc app=leetcode id=475 lang=java
 *
 * [475] Heaters
 */

// @lc code=start
class Solution {
    public int findRadius(int[] houses, int[] heaters) {
        TreeSet<Integer> dict = new TreeSet<>();
        for(var i : heaters){
            dict.add(i);
        }
        int res = 0;
        for(var i : houses){
            var lower = dict.floor(i);
            var higher = dict.ceiling(i);
            int closestDis;
            if(lower == null){
                closestDis = higher - i;
            }else if(higher == null){
                closestDis = i - lower;
            }else{
                closestDis = Integer.min(higher - i, i - lower);
            }
            res = Integer.max(res, closestDis);
        }
        return res;
    }
}
// @lc code=end

