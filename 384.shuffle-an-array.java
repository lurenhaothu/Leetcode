/*
 * @lc app=leetcode id=384 lang=java
 *
 * [384] Shuffle an Array
 */

// @lc code=start
class Solution {
    
    int[] nums;

    public Solution(int[] nums) {
        this.nums = nums;
    }
    
    public int[] reset() {
        return nums;
    }
    
    public int[] shuffle() {
        int res[] = Arrays.copyOf(nums, nums.length);
        for(int i = 1; i < res.length; i++){
            int rand = (int)(Math.random() * (i + 1));
            int temp = res[rand];
            res[rand] = res[i];
            res[i] = temp;
        }
        return res;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int[] param_1 = obj.reset();
 * int[] param_2 = obj.shuffle();
 */
// @lc code=end

