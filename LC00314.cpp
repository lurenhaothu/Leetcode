class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1, -1};
        else if(nums[0] > target || nums[nums.size() - 1] < target) return {-1, -1};
        vector<int> res(2, 0);
        int start, end, pivot;
        if(nums[0] == target) res[0] = 0;
        else{
            start = 0;
            end = nums.size() - 1;
            while(start < end - 1){
                pivot = (start + end) / 2;
                if(nums[pivot] < target){
                    start = pivot;
                }else if(nums[pivot] >= target){
                    end = pivot;
                }
            }
            if(nums[end] == target) res[0] = end;
            else return {-1, -1};
        }
        if(nums[nums.size() - 1] == target) res[1] = nums.size() - 1;
        else{
            start = 0;
            end = nums.size() - 1;
            while(start < end - 1){
                pivot = (start + end) / 2;
                if(nums[pivot] <= target){
                    start = pivot;
                }else if(nums[pivot] > target){
                    end = pivot;
                }
            }
            if(nums[start] == target) res[1] = start;
            else return {-1, -1};
        }
        return res;
    }
};
