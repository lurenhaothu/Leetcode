/*
 * @lc app=leetcode id=289 lang=cpp
 *
 * [289] Game of Life
 */

// @lc code=start
class Solution {
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int nei = neighbor(board, i, j);
                if(board[i][j] == 0 && nei == 3){
                    board[i][j] = 2;
                }else if(board[i][j] == 1){
                    if(nei < 2 || nei > 3) board[i][j] = 1;
                    else board[i][j] = 3;
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                board[i][j] /= 2;
            }
        }
        return;
    }
    
    int neighbor(vector<vector<int>>& board, int i, int j){
        int m = board.size();
        int n = board[0].size();
        int res = 0;
        for(auto dir : dirs){
            int x = i + dir[0];
            int y = j + dir[1];
            if(x < 0 || x >= m) continue;
            if(y < 0 || y >= n) continue;
            res += board[x][y] % 2;
        }
        return res;
    }
};
// @lc code=end

