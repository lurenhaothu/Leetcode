/*
 * @lc app=leetcode id=233 lang=cpp
 *
 * [233] Number of Digit One
 */

// @lc code=start
class Solution {
public:
    int countDigitOne(int n) {
        long long div = 1; //the cur digit position
        int r = 0;
        for(int i = 0; i <= 9 && n / div != 0; i++){
            int dgt = n / div % 10;
            int post = n % div;
            int pri = (n / div - dgt) * div / 10;
            //cout<<dgt<<' '<<post<<' '<<pri<<endl;
            if(dgt == 0) r += pri;
            else if(dgt == 1) r += pri + post + 1;
            else r += pri + div;
            div *= 10;
        }
        return r;
    }
};
// @lc code=end

