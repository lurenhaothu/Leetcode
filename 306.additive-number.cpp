/*
 * @lc app=leetcode id=306 lang=cpp
 *
 * [306] Additive Number
 */

// @lc code=start
class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.length();
        for(int i = 0; i < n / 2; i++){
            for(int j = i + 1; j < n - 1; j++){
                if(helper(num, i, j)) return true;
            }
        }
        return false;
    }
    bool helper(string &num, int i, int j){
        //1: 0-i inclusively
        //2: i + 1 - j inclusively
        long long num1 = stoll(num.substr(0, i + 1));
        long long num2 = stoll(num.substr(i + 1, j - i));
        if(num1 != 0 && num[0] == '0') return false;
        if(num2 != 0 && num[i + 1] == '0') return false;
        long long num3 = num1 + num2;
        int index = j + 1;
        int n = num.length();
        bool found = false;
        while(index < n){
            for(int i = index; i < n && i - index + 1 < 17; i++){
                if(stoll(num.substr(index, i - index + 1)) == num3){
                    if(num3 != 0 && num[index] == '0') continue;
                    num1 = num2;
                    num2 = num3;
                    num3 = num1 + num2;
                    index = i + 1;
                    found = true;
                    break;
                }
            }
            if(found){
                found = false;
                continue;
            }else{
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

