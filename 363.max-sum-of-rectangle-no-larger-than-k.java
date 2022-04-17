/*
 * @lc app=leetcode id=363 lang=java
 *
 * [363] Max Sum of Rectangle No Larger Than K
 */

// @lc code=start
class Solution {
    public int maxSumSubmatrix(int[][] matrix, int k) {
        int m = matrix.length;
        int n = matrix[0].length;
        int[][] sum = new int[m + 1][n + 1];
        for(int i = 0; i < m + 1; i++) sum[i][0] = 0;
        for(int j = 0; j < n + 1; j++) sum[0][j] = 0;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                sum[i][j] = matrix[i - 1][j - 1] + sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
            }
        }
        //System.out.println(Arrays.toString(sum[1]));
        int res = Integer.MIN_VALUE;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                for(int p = i; p <= m; p++){
                    for(int q = j; q <= n; q++){
                        int tempSum = sum[p][q] - sum[p][j - 1] - sum[i - 1][q] + sum[i - 1][j - 1];
                        if(tempSum <= k) res = Integer.max(res, tempSum);
                    }
                }
            }
        }
        return res;
    }
}
// @lc code=end

