class Solution {
public:
    int findMin(vector<int>& nums) {
        return find(nums, 0, nums.size() - 1);
    }
    int find(vector<int>& nums, int start, int end){
        if(start == end) return nums[start];
        int pivot = (start + end) / 2;
        if(nums[start] < nums[pivot] && nums[pivot] <= nums[end]) return nums[start];
        else if(nums[start] < nums[pivot] && nums[pivot] > nums[end]) return find(nums, pivot + 1, end);
        else if(nums[start] == nums[pivot] && nums[pivot] < nums[end]) return nums[start];
        else if(nums[start] == nums[pivot] && nums[pivot] == nums[end]) return min(find(nums, pivot + 1, end), find(nums, start, pivot));
        else if(nums[start] == nums[pivot] && nums[pivot] > nums[end]) return find(nums, pivot + 1, end);
        else if(nums[start] > nums[pivot] && nums[pivot] <= nums[end]) return find(nums, start + 1, pivot);
        return 0;
    }
};
