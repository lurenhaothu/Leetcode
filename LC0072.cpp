class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> DP(n + 1, vector<int>(m + 1, 0));
        for(int i = 0; i < n + 1; i++){
            DP[i][0] = i;
        }
        for(int i = 0; i < m + 1; i++){
            DP[0][i] = i;
        }
        for(int i = 1; i < n + 1; i++){
            for(int j = 1; j < m + 1; j++){
                DP[i][j] = min(DP[i - 1][j] + 1, DP[i][j - 1] + 1);//delete or insert
                if(word1[i - 1] == word2[j - 1]){//replace or do nothing
                    DP[i][j] = min(DP[i][j], DP[i - 1][j - 1]);
                }else{
                   DP[i][j] = min(DP[i][j], DP[i - 1][j - 1] + 1); 
                }
            }
        }
        return DP[n][m];
    }
};
