/*
 * @lc app=leetcode id=386 lang=java
 *
 * [386] Lexicographical Numbers
 */

// @lc code=start
class Solution {
    public List<Integer> lexicalOrder(int n) {
        ArrayList<Integer> res = new ArrayList<>();
        res.add(1);
        int last = 1;
        while(res.size() < n){
            if(last * 10 <= n){
                last *= 10;
                res.add(last);
            }else if(last % 10 != 9 && last + 1 <= n){
                last += 1;
                res.add(last);
            }else if(last % 10 == 9 || last + 1 > n){
                while(last % 10 == 9 || last + 1 > n){
                    last /= 10;
                }
                last++;
                res.add(last);
            }
        }
        return res;
    }
}
// @lc code=end

