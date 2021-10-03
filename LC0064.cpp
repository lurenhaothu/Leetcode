class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> DP(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 && j == 0) DP[i][j] = grid[0][0];
                else if(i == 0){
                    DP[0][j] = DP[0][j - 1] + grid[0][j];
                }else if(j == 0){
                    DP[i][0] = DP[i - 1][0] + grid[i][0];
                }else{
                    DP[i][j] = min(DP[i - 1][j], DP[i][j - 1]) + grid[i][j];
                }
            }
        }
        return DP[n - 1][m - 1];
    }
};
