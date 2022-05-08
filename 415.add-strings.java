/*
 * @lc app=leetcode id=415 lang=java
 *
 * [415] Add Strings
 */

// @lc code=start
class Solution {
    public String addStrings(String num1, String num2) {
        int n1 = num1.length();
        int n2 = num2.length();
        int n = Integer.max(num1.length(), num2.length());
        char[] res = new char[n + 1];
        Arrays.fill(res, '0');
        int carry = 0;
        for(int i = 0; i <= n; i++){
            char c1 = (n1 - 1 - i >= 0) ? num1.charAt(n1 - 1 - i) : '0';
            char c2 = (n2 - 1 - i >= 0) ? num2.charAt(n2 - 1 - i) : '0';
            int temp = (int)(c1 - '0') + (int)(c2 - '0') + carry;
            res[n - i] = (char)('0' + temp % 10);
            carry = temp / 10;
            //System.out.println(new String(res));
        }
        int start = 0;
        while(res[start] == '0' && start < n) start++;
        //String r = Arrays.toString(res, start, n + 1);
        return new String(res).substring(start, n + 1);
    }
}
// @lc code=end

