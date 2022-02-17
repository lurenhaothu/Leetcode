/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> dic;
        while(n != 1){
            if(dic.find(n) != dic.end()) return false;
            dic.insert(n);
            n = op(n);
        }
        return true;
    }

    int op(int n){
        int res = 0;
        while(n > 0){
            res += (n % 10) * (n % 10);
            n /= 10;
        }
        return res;
    }
};
// @lc code=end

