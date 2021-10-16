class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length(), n = t.length();
        vector<vector<unsigned int>> OPT(n + 1, vector<unsigned int>(m + 1, 0));
        for(int i = 0; i < m + 1; i++) OPT[0][i] = 1;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(s[i - 1] == t[j - 1]) OPT[j][i] = OPT[j][i - 1] + OPT[j - 1][i - 1];
                else OPT[j][i] = OPT[j][i - 1];
            }
        }
        return OPT[n][m];
    }
};
