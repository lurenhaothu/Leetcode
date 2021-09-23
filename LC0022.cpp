class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> res;
        vector<vector<int>> left, right;
        res.push_back(vector<string>{"("});
        left.push_back(vector<int>{1});
        right.push_back(vector<int>{0});
        for(int i = 1; i < 2 * n; i++){
            res.push_back(vector<string>{});
            left.push_back(vector<int>{});
            right.push_back(vector<int>{});
            for(int j = 0; j < res[i - 1].size(); j++){
                if(i == 2 * n - 1){
                    if(left[i - 1][j] == right[i - 1][j] + 1){
                        res[i].push_back(res[i - 1][j] + ")");
                    }
                }else if(left[i - 1][j] > right[i - 1][j]){
                    res[i].push_back(res[i - 1][j] + "(");
                    left[i].push_back(left[i - 1][j] + 1);
                    right[i].push_back(right[i - 1][j]);
                    res[i].push_back(res[i - 1][j] + ")");
                    left[i].push_back(left[i - 1][j]);
                    right[i].push_back(right[i - 1][j] + 1);
                }else if(left[i - 1][j] == right[i - 1][j]){
                    res[i].push_back(res[i - 1][j] + "(");
                    left[i].push_back(left[i - 1][j] + 1);
                    right[i].push_back(right[i - 1][j]);
                }
            }
        }
        return res[2 * n - 1];
    }
};
