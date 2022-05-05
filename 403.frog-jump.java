/*
 * @lc app=leetcode id=403 lang=java
 *
 * [403] Frog Jump
 */

// @lc code=start
class Solution {
    public boolean canCross(int[] stones) {
        int n = stones.length;
        if(stones[n - 1] > (n - 1) * n / 2) return false;
        if(stones[1] != 1) return false;
        HashMap<Integer, ArrayList<Integer>> dict = new HashMap<>();
        for(int i : stones){
            dict.put(i, new ArrayList<Integer>());
        }
        dict.get(1).add(1);
        for(int i = 1; i < n; i++){
            int num = stones[i];
            var list = dict.get(num);
            HashSet<Integer> candi = new HashSet<>();
            for(int j : list){
                if(j > 1)candi.add(j - 1);
                candi.add(j);
                candi.add(j + 1);
            }
            for(int k : candi){
                if(dict.containsKey(num + k)){
                    dict.get(num + k).add(k);
                }
            }
        }
        //System.out.println(dict.toString());
        return dict.get(stones[n - 1]).size() != 0;
    }
}
// @lc code=end

