class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1, pivot;
        while(start <= end){
            int s = start, e = end;
            if(start == end){
                if(nums[start] == target) return start;
                else return -1;
            }else if(start == end - 1){
                if(nums[start] == target) return start;
                else if(nums[end] == target) return end;
                else return -1;
            }
            pivot = (start + end) / 2;
            if(nums[start] > nums[pivot]){
                if(target >= nums[start] || target <= nums[pivot]){
                    end = pivot;
                }
            }else{
                if(target >= nums[start] && target <= nums[pivot]){
                    end = pivot;
                }
            }
            if(nums[pivot] > nums[end]){
                if(target >= nums[pivot] || target <= nums[end]){
                    start = pivot;
                }
            }else{
                if(target >= nums[pivot] && target <= nums[end]){
                    start = pivot;
                }
            }
            if(s == start && e == end) return -1;
        }
        return -1;
    }
};
