/*
 * @lc app=leetcode id=398 lang=java
 *
 * [398] Random Pick Index
 */

// @lc code=start
class Solution {
    private HashMap<Integer, List<Integer>> map;
    public Solution(int[] nums) {
        map = new HashMap<Integer, List<Integer>>();
        for(int i = 0; i < nums.length; i++){
            int num = nums[i];
            if(!map.containsKey(num)) map.put(num, new ArrayList<Integer>());
            map.get(num).add(i);
        }
    }
    
    public int pick(int target) {
        var list = map.get(target);
        int size = list.size();
        int rand = (int)(Math.random() * size);
        return list.get(rand);
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
// @lc code=end

