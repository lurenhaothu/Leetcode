/*
 * @lc app=leetcode id=388 lang=java
 *
 * [388] Longest Absolute File Path
 */

// @lc code=start
class Solution {
    public int lengthLongestPath(String input) {
        MyPath myPath = new MyPath(input);
        ArrayList<String> res = new ArrayList<>();
        int maxLen = 0;
        while(myPath.hasNext()){
            var nextPair = myPath.next();
            
            while(nextPair.getValue() < res.size()){
                res.remove(res.size() - 1);
            }
            res.add(nextPair.getKey());
            if(MyPath.isFile(nextPair.getKey())){
                maxLen = Integer.max(maxLen, MyPath.pathLength(res));
            }
            //System.out.println(nextPair.getValue());
        }
        return maxLen;
    }
}

class MyPath{
    private char[] input;
    private int ptr;
    public MyPath(String in){
        this.input = in.toCharArray();
        ptr = 0;
    }
    public Pair<String, Integer> next(){
        int num = 0;
        while(input[ptr] == '\t' || input[ptr] == '\n'){
            if(input[ptr] == '\t') num++;
            ptr++;
        }
        String res = "";
        while(ptr < input.length && input[ptr] != '\n'){
            res += input[ptr];
            ptr++;
        }
        return new Pair<String, Integer>(res, num);
    }
    
    public boolean hasNext(){
        return ptr < input.length;
    }
    public static boolean isFile(String s){
        for(char c : s.toCharArray()){
            if(c == '.') return true;
        }
        return false;
    }
    public static int pathLength(List<String> r){
        int res = 0;
        for(String s : r){
            res += s.length();
        }
        return res + r.size() - 1;
    }
}
// @lc code=end

