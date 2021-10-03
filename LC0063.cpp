class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<int>> DP(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(obstacleGrid[i][j] == 1) DP[i][j] = 0;
                else{
                    if(i == 0 && j == 0) DP[i][j] = 1;
                    else if(i == 0){
                        DP[0][j] = DP[0][j - 1];
                    }else if(j == 0){
                        DP[i][0] = DP[i - 1][0];
                    }else{
                        DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
                    }
                }
            }
        }
        return DP[n - 1][m - 1];
    }
};
