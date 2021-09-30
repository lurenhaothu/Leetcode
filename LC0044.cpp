class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        vector<vector<bool>> OPT(n + 1, vector<bool>(m + 1, false));
        //base case
        OPT[0][0] = true;
        for(int i = 1; i <= m; i++){
            if(p[i - 1] == '*') OPT[0][i] = true;
            else break;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(p[j - 1] == '*'){
                    OPT[i][j] = OPT[i - 1][j] || OPT[i][j - 1] || OPT[i - 1][j - 1];
                }else if(p[j - 1] == '?'){
                    OPT[i][j] = OPT[i - 1][j - 1];
                }else{
                    OPT[i][j] = OPT[i - 1][j - 1] && (s[i - 1] == p[j - 1]);
                }
            }
        }
        return OPT[n][m];
    }
};
