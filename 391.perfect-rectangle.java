/*
 * @lc app=leetcode id=391 lang=java
 *
 * [391] Perfect Rectangle
 */

// @lc code=start
class Solution {
    public boolean isRectangleCover(int[][] rectangles) {
        int n = rectangles.length;
        int x1 = Integer.MAX_VALUE;
        int y1 = Integer.MAX_VALUE;
        int x2 = Integer.MIN_VALUE;
        int y2 = Integer.MIN_VALUE;
        int areaSum = 0;
        for(int i = 0; i < n; i++){
            areaSum += area(rectangles[i]);
            x1 = Integer.min(x1, rectangles[i][0]);
            y1 = Integer.min(y1, rectangles[i][1]);
            x2 = Integer.max(x2, rectangles[i][2]);
            y2 = Integer.max(y2, rectangles[i][3]);
            for(int j = i + 1; j < n; j++){
                if(helper(rectangles[i], rectangles[j])) return false;
            }
        }
        return areaSum == (x2 - x1) * (y2 - y1);
    }
    
    private boolean helper(int[] a, int[] b){
        return overlap(a[0], a[2], b[0], b[2]) && overlap(a[1], a[3], b[1], b[3]);
    }
    
    private boolean overlap(int a, int b, int c, int d){
        if(b <= c) return false;
        if(d <= a) return false;
        return true;
    }
    
    private int area(int[] a){
        return (a[2] - a[0]) * (a[3] - a[1]);
    }
}
// @lc code=end

