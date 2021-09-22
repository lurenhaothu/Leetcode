class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int sum = nums[1] + nums[2] + nums[3];
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n - 2; i++){
            int j = i + 1, k = n - 1;
            while(j < k){
                int s = nums[i] + nums[j] + nums[k];
                sum = abs(s - target) < abs(sum - target) ? s : sum;
                if(s > target) k--;
                else if(s < target) j++;
                else if(s == target) return target;
            }
        }
        return sum;
    }
};
