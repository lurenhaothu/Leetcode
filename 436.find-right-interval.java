/*
 * @lc app=leetcode id=436 lang=java
 *
 * [436] Find Right Interval
 */

// @lc code=start
class Solution {
    public int[] findRightInterval(int[][] intervals) {
        TreeMap<Integer, Integer> dict = new TreeMap<>();
        int n = intervals.length;
        for(int i = 0; i < n; i++){
            dict.put(intervals[i][0], i);
        }
        int[] res = new int[n];
        for(int i = 0; i < n; i++){
            Integer r = dict.ceilingKey(intervals[i][1]);
            if(r == null) res[i] = -1;
            else res[i] = dict.get(r);
        }
        return res;
    }
}
// @lc code=end

