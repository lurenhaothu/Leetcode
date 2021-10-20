class Solution {
public:
    int minCut(string s) {
        if(s.length() == 1) return 0;
        int n = s.length();
        vector<vector<bool>> palSet(n, vector<bool>(n, false));
        for(int i = 0; i < n; i++){
            palSet[i][i] = true;
            if(i + 1 < n && s[i] == s[i + 1]) palSet[i][i + 1] = true;
        }
        for(int l = 3; l <= n; l++){
            for(int i = 0; i <= n - l; i++){
                if(palSet[i + 1][i + l - 2] && s[i] == s[i + l - 1]){
                    palSet[i][i + l - 1] = true;
                }
            }
        }
        /*for(auto a : palSet){
            for(auto i : a){
                cout<<i<<' ';
            }
            cout<<endl;
        }*/
        vector<int> OPT(n + 1, 0);//OPT[i] is the minimum cut number for substring [i, n - 1]
        // recursion: OPT[i] = 1 + min{OPT[j + 1]}, where j is any palSet[i]
        // base case: OPT[n] = -1;
        OPT[n] = -1;
        for(int i = n - 1; i >= 0; i--){
            int minOPT = INT_MAX;
            for(int j = i; j < n; j++){
                if(palSet[i][j]) minOPT = min(minOPT, OPT[j + 1]);
            }
            OPT[i] = 1 + minOPT;
        }
        return OPT[0];
    }
};
