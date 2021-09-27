class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> sorted, candnum;
        for(int i = 0; i < candidates.size(); i++){
            if(i == 0){
                sorted.push_back(candidates[i]);
                candnum.push_back(1);
            }else{
                if(candidates[i] == sorted[sorted.size() - 1]){
                    candnum[sorted.size() - 1]++;
                }else{
                    sorted.push_back(candidates[i]);
                    candnum.push_back(1);
                }
            }
        }
        return combinationSum(sorted, candnum, target);
    }
    vector<vector<int>> combinationSum(vector<int>& sorted, vector<int>& candnum, int target) {
        vector<vector<int>> res;
        if(target == 0){
            res.push_back(vector<int>{});
            return res;
        }
        for(int i = sorted.size() - 1; i >= 0; i--){
            if(sorted[i] > target) continue;
            vector<vector<int>> res1;
            if(candnum[i] > 1){
                vector<int> newsorted(sorted.begin(), sorted.begin() + i + 1);
                vector<int> newcandnum(candnum.begin(), candnum.begin() + i + 1);
                newcandnum[i]--;
                res1 = combinationSum(newsorted, newcandnum, target - sorted[i]);
            }else{
                vector<int> newsorted(sorted.begin(), sorted.begin() + i);
                vector<int> newcandnum(candnum.begin(), candnum.begin() + i);
                res1 = combinationSum(newsorted, newcandnum, target - sorted[i]);
            }
            if(res1.size() == 0) continue;
            for(int j = 0; j < res1.size(); j++){
                res1[j].push_back(sorted[i]);
                res.push_back(res1[j]);
                //cout<<i<<" "<<res.size()<<endl;
            }
        }
        return res;
    }
};
