class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> ref({1});
        vector<vector<int>> res;//({}, {nums[0]});
        int size = pow(2, n);
        for(int i = 0; i < size; i++){
            vector<int> comb;
            int k = i;
            for(int j = 0; j < n; j++){
                if(k & 1) comb.push_back(nums[j]);
                k = k >> 1;
            }
            res.push_back(comb);
        }
        return(res);
    }
};
