/*
 * @lc app=leetcode id=435 lang=java
 *
 * [435] Non-overlapping Intervals
 */

// @lc code=start
class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        Arrays.sort(intervals, (i, j)->{return i[0] == j[0] ? i[1] - j[1] : i[0] - j[0];});
        System.out.println(Arrays.deepToString(intervals));
        HashMap<String, Integer> dict = new HashMap<String, Integer>();
        return DFS(intervals, 0, Integer.MIN_VALUE, dict);
    }
    private int DFS(int[][] intervals, int index, int end, HashMap<String, Integer> dict){
        if(index == intervals.length) return 0;
        String key = Integer.toString(index) + ' ' + Integer.toString(end);
        if(dict.containsKey(key)) return dict.get(key);
        var interval = intervals[index];
        int res = Integer.MAX_VALUE;
        if(interval[0] < end){
            res = Integer.min(res, 1 + DFS(intervals, index + 1, end, dict));
        }else{
            res = Integer.min(res, DFS(intervals, index + 1, interval[1], dict));
            res = Integer.min(res, 1 + DFS(intervals, index + 1, end, dict));
        }
        dict.put(key, res);
        return res;
    }
}
// @lc code=end

