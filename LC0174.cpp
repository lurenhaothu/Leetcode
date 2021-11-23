class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        if(m == 1 && n == 1) return max(1, 1 - dungeon[0][0]);
        else if(m == 1){
            vector<int> OPT = vector<int>(n, 0);
            OPT[n - 1] = min(0, dungeon[0][n - 1]);
            for(int i = n - 2; i >= 0; i--){
                OPT[i] = min(0, OPT[i + 1] + dungeon[0][i]);
            }
            return 1 - OPT[0];
        }else if(n == 1){
            vector<int> OPT = vector<int>(m, 0);
            OPT[m - 1] = min(0, dungeon[m - 1][0]);
            for(int i = m - 2; i >= 0; i--){
                OPT[i] = min(0, OPT[i + 1] + dungeon[i][0]);
            }
            return 1 - OPT[0];
        }
        vector<vector<int>> OPT = vector<vector<int>>(m, vector<int>(n, 0));
        OPT[m - 1][n - 1] = min(0, dungeon[m - 1][n - 1]);
        for(int i = n - 2; i >= 0; i--){
            OPT[m - 1][i] = min(0, OPT[m - 1][i + 1] + dungeon[m - 1][i]);
        }
        for(int j = m - 2; j >= 0; j--){
            OPT[j][n - 1] = min(0, OPT[j + 1][n - 1] + dungeon[j][n - 1]);
        }
        for(int i = n - 2; i >= 0; i--){
            for(int j = m - 2; j >= 0; j--){
                OPT[j][i] = min(0, max(OPT[j + 1][i], OPT[j][i + 1]) + dungeon[j][i]);
            }
        }
        return 1 - OPT[0][0];
    }
};
