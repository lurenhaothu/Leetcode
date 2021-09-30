class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> norep, freq;
        for(int i = 0; i < nums.size(); i++){
            if(i == 0){
                norep.push_back(nums[i]);
                freq.push_back(1);
            }else if(nums[i] == nums[i - 1]){
                freq[freq.size() - 1]++;
            }else{
                norep.push_back(nums[i]);
                freq.push_back(1);
            }
        }
        int n = norep.size();
        vector<vector<vector<int>>> res;
        vector<vector<vector<int>>> mark;
        res.push_back(vector<vector<int>>(1, vector<int>{}));
        mark.push_back(vector<vector<int>>(1, freq));
        for(int i = 0; i < nums.size(); i++){
            res.push_back(vector<vector<int>>{});
            mark.push_back(vector<vector<int>>{});
            for(int j = 0; j < res[i].size(); j++){
                for(int k = 0; k < n; k++){
                    if(mark[i][j][k] != 0){
                        res[i + 1].push_back(res[i][j]);
                        mark[i + 1].push_back(mark[i][j]);
                        res[i + 1][res[i + 1].size() - 1].push_back(norep[k]);
                        mark[i + 1][res[i + 1].size() - 1][k]--;
                    }
                }
            }
        }
        return res[nums.size()];
    }
};
