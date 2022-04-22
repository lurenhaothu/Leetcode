/*
 * @lc app=leetcode id=376 lang=java
 *
 * [376] Wiggle Subsequence
 */

// @lc code=start
class Solution {
    public int wiggleMaxLength(int[] nums) {
        int status = 0;
        int res = 1;
        for(int i = 1; i < nums.length; i++){
            switch(status){
                case 0:
                    if(nums[i] == nums[i - 1]){
                        continue;
                    }else if(nums[i] > nums[i - 1]){
                        status = 1;
                        res++;
                    }else{
                        status = -1;
                        res++;
                    }
                    break;
                case 1:
                    if(nums[i] == nums[i - 1]){
                        continue;
                    }else if(nums[i] > nums[i - 1]){
                        continue;
                    }else{
                        status = -1;
                        res++;
                    }
                    break;
                case -1:
                    if(nums[i] == nums[i - 1]){
                        continue;
                    }else if(nums[i] > nums[i - 1]){
                        status = 1;
                        res++;
                    }else{
                        continue;
                    }
                    break;
            }
        }
        return res;
    }
}
// @lc code=end

