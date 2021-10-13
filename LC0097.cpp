class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.length(), l2 = s2.length();
        if(l1 + l2 != s3.length()) return false;
        vector<vector<bool>> OPT(l1 + 1, vector<bool>(l2 + 1, false));
        for(int i = 0; i <= l1; i++){
            for(int j = 0; j <= l2; j++){
                if(i == 0 && j == 0) OPT[i][j] = true;
                else{
                    if(i - 1 >= 0) OPT[i][j] = OPT[i][j] || ((s3[i + j - 1] == s1[i - 1]) && (OPT[i - 1][j]));
                    if(j - 1 >= 0) OPT[i][j] = OPT[i][j] || ((s3[i + j - 1] == s2[j - 1]) && (OPT[i][j - 1]));
                }
                
            }
        }
        return OPT[l1][l2];
    }
};
