class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int maxl = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        if(n == 1) return maxl;
        for(int i = 0; i < n - 1; i++){
            maxl = max(maxl, nums[i + 1] - nums[i]);
        }
        return maxl;
    }
};
