/*
 * @lc app=leetcode id=419 lang=java
 *
 * [419] Battleships in a Board
 */

// @lc code=start
class Solution {
    public int countBattleships(char[][] board) {
        int m = board.length;
        int n = board[0].length;
        int res = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'X'){
                    res++;
                    if(i + 1 < m && board[i + 1][j] == 'X'){
                        int ii = i;
                        while(ii + 1 < m && board[ii + 1][j] == 'X'){
                            board[ii + 1][j] = '.';
                            ii++;
                        }
                    }else if(j + 1 < n && board[i][j + 1] == 'X'){
                        int jj = j;
                        while(jj + 1 < n && board[i][jj + 1] == 'X'){
                            board[i][jj + 1] = '.';
                            jj++;
                        }
                    }
                }
            }
        }
        return res;
    }
}
// @lc code=end

