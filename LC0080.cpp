class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cur = -1e5, time, p1, p2 = 0;
        for(p1 = 0; p1 < nums.size(); p1++){
            if(nums[p1] == cur) time++;
            else{
                cur = nums[p1];
                time = 1;
            }
            if(time <= 2){
                nums[p2] = cur;
                p2++;
            }
        }
        return p2;
    }
};
