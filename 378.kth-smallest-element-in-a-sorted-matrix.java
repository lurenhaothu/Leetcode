/*
 * @lc app=leetcode id=378 lang=java
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */

// @lc code=start
class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        int n = matrix.length;
        int start = matrix[0][0];
        int end = matrix[n - 1][n - 1];
        int pivot;
        while(start < end){
            pivot = (int)Math.floor((double)(start + end) / 2);
            int count = helper(matrix, pivot);
            if(count >= k){
                end = pivot;
            }else{
                start = pivot + 1;
            }
        }
        return start;
    }
    private int helper(int[][] matrix, int pivot){
        int n = matrix.length;
        int i = n - 1, j = 0;
        int res = 0;
        for(; j < n; j++){
            while(i >= 0 && matrix[i][j] > pivot) i--;
            res += i + 1;
        }
        return res;
    }
}
// @lc code=end

