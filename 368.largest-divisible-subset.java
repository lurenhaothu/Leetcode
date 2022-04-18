/*
 * @lc app=leetcode id=368 lang=java
 *
 * [368] Largest Divisible Subset
 */

// @lc code=start
class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        int n = nums.length;
        ArrayList<ArrayList<Integer>> dp = new ArrayList<ArrayList<Integer>>();
        Arrays.sort(nums);
        dp.add(new ArrayList<Integer>());
        dp.get(0).add(nums[0]);
        int maxLen = 0;
        List<Integer> res = dp.get(0);
        for(int i = 1; i < n; i++){
            dp.add(new ArrayList<Integer>());
            dp.get(i).add(nums[i]);
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0 && dp.get(i).size() < dp.get(j).size() + 1){
                    dp.set(i, (ArrayList<Integer>) dp.get(j).clone());
                    dp.get(i).add(nums[i]);
                }
            }
            if(maxLen < dp.get(i).size()){
                maxLen = dp.get(i).size();
                res = dp.get(i);
            }
        }
        return res;
    }
}
// @lc code=end

