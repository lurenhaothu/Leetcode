class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int pivot, left = 0, right = nums.size() - 1;
        if(nums[0] >= target) return 0;
        else if(nums[right] == target) return right;
        else if(nums[right] < target) return right + 1;
        while(left + 1 != right){
            pivot = (left + right) / 2;
            if(nums[pivot] == target) return pivot;
            else if(nums[pivot] > target) right = pivot;
            else left = pivot;
        }
        if(nums[left] == target) return left;
        else return right;
    }
};
