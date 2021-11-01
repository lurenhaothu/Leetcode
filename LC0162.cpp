class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        if(n == 2) return nums[0] > nums[1] ? 0 : 1;
        int start = 0, end = n - 1, pivot;
        while(start < end - 1){
            pivot = (start + end) / 2;
            if(nums[pivot - 1] > nums[pivot]){
                end = pivot - 1;
            }else if(nums[pivot] < nums[pivot + 1]){
                start = pivot + 1;
            }else{
                return pivot;
            }
        }
        if(start == end) return start;
        else return nums[start] > nums[end] ? start : end;
    }
};
