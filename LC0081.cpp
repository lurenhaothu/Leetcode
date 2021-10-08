class Solution {
public:
    bool search(vector<int>& nums, int target) {//solve by divide and conquer
        return find(nums, target, 0, nums.size() - 1);
    }
    
    bool find(vector<int>& nums, int target, int s, int t){
        if(s + 1 == t) return (nums[s] == target || nums[t] == target);
        else if(s == t) return (nums[s] == target);
        int pivot = (s + t) / 2;
        if(nums[pivot] == target) return true;
        if(nums[s] < nums[pivot]){
            if(nums[s] <= target && target <= nums[pivot]){
                if(find(nums, target, s, pivot - 1)) return true;
            }
        }else if(nums[s] > nums[pivot]){
            if(nums[s] <= target || target <= nums[pivot]){
                if(find(nums, target, s, pivot - 1)) return true;
            }
        }else{
            if(find(nums, target, s, pivot - 1)) return true;
        }
        if(nums[pivot] < nums[t]){
            if(nums[pivot] <= target && target <= nums[t]){
                if(find(nums, target, pivot + 1, t)) return true;
            }
        }else if(nums[pivot] > nums[t]){
            if(nums[pivot] <= target || target <= nums[t]){
                if(find(nums, target, pivot + 1, t)) return true;
            }
        }else{
            if(find(nums, target, pivot + 1, t)) return true;
        }
        return false;
    }
};
