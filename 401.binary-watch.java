/*
 * @lc app=leetcode id=401 lang=java
 *
 * [401] Binary Watch
 */

// @lc code=start
class Solution {
    public List<String> readBinaryWatch(int turnedOn) {
        HashMap<Integer, List<Integer>> dictHour = new HashMap<>();
        HashMap<Integer, List<Integer>> dictMin = new HashMap<>();
        for(int i = 0; i <= 11; i++){
            int count = Integer.bitCount(i);
            if(!dictHour.containsKey(count)) dictHour.put(count, new ArrayList<Integer>());
            dictHour.get(count).add(i);
        }
        for(int i = 0; i < 60; i++){
            int count = Integer.bitCount(i);
            if(!dictMin.containsKey(count)) dictMin.put(count, new ArrayList<Integer>());
            dictMin.get(count).add(i);
        }
        ArrayList<String> res = new ArrayList<>();
        for(int i = 0; i <= turnedOn; i++){
            int j = turnedOn - i;
            if(dictHour.get(i) == null) continue;
            for(int h : dictHour.get(i)){
                if(dictMin.get(j) == null) continue;
                for(int m : dictMin.get(j)){
                    res.add(helper(h, m));
                }
            }
        }
        return res;
    }
    String helper(int h, int m){
        if(m < 10) return Integer.toString(h) + ':' + '0' + Integer.toString(m);
        else return Integer.toString(h) + ':' + Integer.toString(m);
    }
}
// @lc code=end

