/*
 * @lc app=leetcode id=400 lang=java
 *
 * [400] Nth Digit
 */

// @lc code=start
class Solution {
    public int findNthDigit(int n) {
        long a = 1;
        long i = 1;
        while(n > a * i * 9){
            n -= a * i * 9;
            a *= 10;
            i++;
        }
        long id = (n - 1) / i + 1;
        long offset = (n - 1) % i + 1;
        long num = id + a - 1;
        //System.out.println(id);
        //System.out.println(offset);
        //System.out.println(num);
        //System.out.println(a);
        for(int j = 0; j < i - offset; j++) num /= 10;
        return (int)num % 10;
    }
}
// @lc code=end

