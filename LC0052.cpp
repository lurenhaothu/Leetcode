class Solution {
public:
    int totalNQueens(int n) {
                vector<vector<vector<string>>> res;
        vector<vector<int>> mark;
        res.push_back(vector<vector<string>> {vector<string>(n, string(n, '.'))});
        mark.push_back(vector<int>{-1});
        for(int i = 0; i < n; i++){
            res.push_back(vector<vector<string>>{});
            mark.push_back(vector<int>{});
            for(int j = 0; j < res[i].size(); j++){
                for(int m = mark[i][j] + 1; m < n * n; m++){
                    int k = m / n;
                    int p = m % n;
                    if(res[i][j][k][p] == '.'){
                        res[i + 1].push_back(res[i][j]);
                        res[i + 1][res[i + 1].size() - 1][k][p] = 'Q';
                        mark[i + 1].push_back(k * n  + p);
                        for(int q = 0; q < n; q++){
                            if(res[i + 1][res[i + 1].size() - 1][k][q] == '.'){
                                res[i + 1][res[i + 1].size() - 1][k][q] = 'X';
                            }
                            if(res[i + 1][res[i + 1].size() - 1][q][p] == '.'){
                                res[i + 1][res[i + 1].size() - 1][q][p] = 'X';
                            }
                        }
                        for(int q = 0; q < n; q++){
                            if(k + q < n && p + q < n){
                                if(res[i + 1][res[i + 1].size() - 1][k + q][p + q] == '.'){
                                    res[i + 1][res[i + 1].size() - 1][k + q][p + q] = 'X';
                                }
                            }
                            if(k - q >= 0 && p - q >= 0){
                                if(res[i + 1][res[i + 1].size() - 1][k - q][p - q] == '.'){
                                    res[i + 1][res[i + 1].size() - 1][k - q][p - q] = 'X';
                                }
                            }
                            if(k - q >= 0 && p + q < n){
                                if(res[i + 1][res[i + 1].size() - 1][k - q][p + q] == '.'){
                                    res[i + 1][res[i + 1].size() - 1][k - q][p + q] = 'X';
                                }
                            }
                            if(k + q < n && p - q >= 0){
                                if(res[i + 1][res[i + 1].size() - 1][k + q][p - q] == '.'){
                                    res[i + 1][res[i + 1].size() - 1][k + q][p - q] = 'X';
                                }
                            }
                        }
                    }
                }
            }
        }
        /*
        for(int i = 0; i < res[n].size(); i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    if(res[n][i][j][k] == 'X') res[n][i][j][k] = '.';
                }
            }
        }*/
        return res[n].size();
    }
};
