class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i < pow(2, nums.size()); i++){
            vector<int> r;
            bool f = true;
            for(int j = 0; j < nums.size(); j++){
                int k = 1<<j;
                if(i & k){
                    if((j > 0) && (nums[j] == nums[j - 1]) && !(i & k>>1)){
                        f = false;
                    }else{
                        r.push_back(nums[j]);
                    }
                }
            }
            if(f) res.push_back(r);
        }
        return res;
    }
};
