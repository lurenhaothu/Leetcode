/*
 * @lc app=leetcode id=414 lang=java
 *
 * [414] Third Maximum Number
 */

// @lc code=start
class Solution {
    public int thirdMax(int[] nums) {
        ArrayList<Integer> que = new ArrayList<>();
        for(int i : nums){
            if(que.isEmpty()) que.add(i);
            else if(i < que.get(que.size() - 1)){
                que.add(i);
            }else{
                for(int j = 0; j < que.size(); j++){
                    if(i == que.get(j)) break;
                    if(i > que.get(j)){
                        que.add(j, i); break;
                    }
                }
            }
            if(que.size() == 4) que.remove(3);
            //System.out.println(que.toString());
        }
        if(que.size() == 3) return que.get(que.size() - 1);
        else return que.get(0);
    }
}
// @lc code=end

