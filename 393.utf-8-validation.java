/*
 * @lc app=leetcode id=393 lang=java
 *
 * [393] UTF-8 Validation
 */

// @lc code=start
class Solution {
    public boolean validUtf8(int[] data) {
        int n = data.length;
        int i = 0;
        while(i < n){
            int d = data[i];
            if((d >> 7) == 0){
                i++;
                continue;
            }
            int num = numOne(d);
            if(num == 1 || num > 4) return false;
            //System.out.println(num);
            for(int j = i + 1; j < i + num; j++){
                if(j >= n) return false;
                if((data[j] >> 6) != 2) return false;
            }
            i = i + num;
        }
        return true;
    }
    
    private int numOne(int d){
        for(int i = 7; i >= 0; i--){
            if(((d >> i)&1) == 1) continue;
            else return 7 - i;
        }
        return 8;
    }
}
// @lc code=end

