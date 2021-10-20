class Solution {
public:
    vector<vector<string>> res;
    string sample;
    int n;
    vector<vector<bool>> palSet;
    vector<vector<string>> partition(string s) {
        if(s.length() == 1) return {{s}};
        n = s.length();
        palSet = vector<vector<bool>>(n, vector<bool>(n, false));
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
        vector<string> r;
        sample = s;
        DFS(0, r);
        return res;
    }
    void DFS(int start, vector<string> &r){ //begin from start (including start), continue explore, record in r
        if(start == n){ 
            res.push_back(r);
            return;
        }
        for(int j = start; j < n; j++){
            if(palSet[start][j]){
                r.push_back(sample.substr(start, j - start + 1));
                DFS(j + 1, r);
                r.pop_back();
            }
        }
        return;
    }
};
