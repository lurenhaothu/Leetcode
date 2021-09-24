class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cur = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            if(i == 0){
                cur++;
            }else{
                if(nums[i] != nums[i - 1]){
                    nums[cur] = nums[i];
                    cur++;
                }
            }
        }
        return cur;
    }
};
