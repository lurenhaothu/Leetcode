/*
 * @lc app=leetcode id=427 lang=java
 *
 * [427] Construct Quad Tree
 */

// @lc code=start
/*
// Definition for a QuadTree node.
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;

    
    public Node() {
        this.val = false;
        this.isLeaf = false;
        this.topLeft = null;
        this.topRight = null;
        this.bottomLeft = null;
        this.bottomRight = null;
    }
    
    public Node(boolean val, boolean isLeaf) {
        this.val = val;
        this.isLeaf = isLeaf;
        this.topLeft = null;
        this.topRight = null;
        this.bottomLeft = null;
        this.bottomRight = null;
    }
    
    public Node(boolean val, boolean isLeaf, Node topLeft, Node topRight, Node bottomLeft, Node bottomRight) {
        this.val = val;
        this.isLeaf = isLeaf;
        this.topLeft = topLeft;
        this.topRight = topRight;
        this.bottomLeft = bottomLeft;
        this.bottomRight = bottomRight;
    }
};
*/

class Solution {
    public Node construct(int[][] grid) {
        int n = grid.length;
        return helper(grid, 0, n - 1, 0, n - 1);
    }
    private Node helper(int[][]grid, int x1, int x2, int y1, int y2){
        if(x1 == x2 && y1 == y2){
            return new Node(grid[x1][y1] == 1, true);
        }
        int len = x2 - x1 + 1;
        var topLeft = helper(grid, x1, x1 + len / 2 - 1, y1, y1 + len / 2 - 1);
        var topRight = helper(grid, x1, x1 + len / 2 - 1, y1 + len / 2, y2);
        var bottomLeft = helper(grid, x1 + len / 2, x2, y1, y1 + len / 2 - 1);
        var bottomRight = helper(grid, x1 + len / 2, x2, y1 + len / 2, y2);
        if(topLeft.isLeaf && topRight.isLeaf && bottomLeft.isLeaf && bottomRight.isLeaf
          && topLeft.val == topRight.val && bottomLeft.val == bottomRight.val && topLeft.val == bottomLeft.val){
            return new Node(topLeft.val, true);
        }else{
            return new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
        }
    }
}
// @lc code=end

