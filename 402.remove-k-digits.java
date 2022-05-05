/*
 * @lc app=leetcode id=402 lang=java
 *
 * [402] Remove K Digits
 */

// @lc code=start
class Solution {
    public String removeKdigits(String num, int k) {
        if(k == num.length()) return "0";
        ArrayDeque<Character> res = new ArrayDeque<>();
        int numPop = 0;
        for(int i = 0; i < num.length(); i++){
            char c = num.charAt(i);
            if(res.isEmpty() || res.peekLast() <= c){
                res.add(c);
            }else{
                while(numPop < k && !res.isEmpty() && res.peekLast() > c){
                    res.pollLast();
                    numPop++;
                }
                res.add(c);
            }
        }
        while(numPop < k){
            res.pollLast();
            numPop++;
        }
        while(res.peekFirst() == '0' && res.size() > 1){
            res.pollFirst();
        }
        //return res.stream().map(e -> e.toString()).reduce((a, b) -> a + b).get();
        StringBuilder resBuilder = new StringBuilder();
        for(char c : res) resBuilder.append(c);
        return resBuilder.toString();
    }
}
// @lc code=end

