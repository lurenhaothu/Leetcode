/*
 * @lc app=leetcode id=412 lang=java
 *
 * [412] Fizz Buzz
 */

// @lc code=start
class Solution {
    public List<String> fizzBuzz(int n) {
        ArrayList<String> res = new ArrayList<>();
        for(int i = 1; i <= n; i++){
            if(i % 3 == 0 && i % 5 == 0){
                res.add("FizzBuzz");
            }else if(i % 3 == 0){
                res.add("Fizz");
            }else if(i % 5 == 0){
                res.add("Buzz");
            }else{
                res.add(Integer.toString(i));
            }
        }
        return res;
    }
}
// @lc code=end

