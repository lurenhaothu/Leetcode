class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size() - 1, pivot;
        while(start < end){
            pivot = (start + end) / 2;
            if(nums[start] <= nums[pivot] && nums[pivot] <= nums[end]) return nums[start];
            else if(nums[start] <= nums[pivot] && nums[pivot] > nums[end]) start = pivot + 1;
            else if(nums[start] > nums[pivot] && nums[pivot] <= nums[end]) end = pivot, start++;
        }
        return nums[start];
    }
};
