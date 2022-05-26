/*
 * @lc app=leetcode id=437 lang=java
 *
 * [437] Path Sum III
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int pathSum(TreeNode root, int targetSum) {
        return helper(root, targetSum, false);
    }
    public int helper(TreeNode root, int targetSum, boolean hasRoot) {
        if(root == null) return 0;
        int res = 0;
        if(root.val == targetSum) res++;
        if(hasRoot){
            res += helper(root.left, targetSum - root.val, true);
            res += helper(root.right, targetSum - root.val, true);
        }else{
            res += helper(root.left, targetSum, false);
            res += helper(root.left, targetSum - root.val, true);
            res += helper(root.right, targetSum, false);
            res += helper(root.right, targetSum - root.val, true);
        }
        //System.out.println(Integer.toString(root.val) + " : " + Integer.toString(targetSum) +  ", " + Integer.toString(res));
        return res;
    }
}
// @lc code=end

