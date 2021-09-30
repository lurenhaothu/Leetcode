class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>> res;
        vector<vector<vector<bool>>> mark;
        res.push_back(vector<vector<int>>(1, vector<int>{}));
        mark.push_back(vector<vector<bool>>(1, vector<bool>(n, false)));
        for(int i = 0; i < n; i++){
            res.push_back(vector<vector<int>>{});
            mark.push_back(vector<vector<bool>>{});
            for(int j = 0; j < res[i].size(); j++){
                for(int k = 0; k < n; k++){
                    if(!mark[i][j][k]){
                        res[i + 1].push_back(res[i][j]);
                        mark[i + 1].push_back(mark[i][j]);
                        res[i + 1][res[i + 1].size() - 1].push_back(nums[k]);
                        mark[i + 1][res[i + 1].size() - 1][k] = true;
                    }
                }
            }
        }
        return res[n];
    }
};
