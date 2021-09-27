class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if(candidates.size() == 0 || target == 0){
            res.push_back(vector<int>{});
            return res;
        }
        for(int i = candidates.size() - 1; i >= 0; i--){
            if(candidates[i] > target) continue;
            vector<int> new_candidates(candidates.begin(), candidates.begin() + i + 1);
            
            vector<vector<int>> res1 = combinationSum(new_candidates, target - candidates[i]);
            
            if(res1.size() == 0) continue;
            for(int j = 0; j < res1.size(); j++){
                res1[j].push_back(candidates[i]);
                res.push_back(res1[j]);
                //cout<<i<<" "<<res.size()<<endl;
            }
        }
        return res;
    }
};
