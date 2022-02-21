/*
 * @lc app=leetcode id=223 lang=cpp
 *
 * [223] Rectangle Area
 */

// @lc code=start
class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int s1 = (ax2 - ax1) * (ay2 - ay1);
        int s2 = (bx2 - bx1) * (by2 - by1);
        int mx1 = max(ax1, bx1);
        int mx2 = min(ax2, bx2);
        if(mx1 >= mx2) return s1 + s2;
        int my1 = max(ay1, by1);
        int my2 = min(ay2, by2);
        if(my1 >= my2) return s1 + s2;
        else return s1 + s2 - (mx2 - mx1) * (my2 - my1);
    }
};
// @lc code=end

