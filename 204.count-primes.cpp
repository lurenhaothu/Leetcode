/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */

// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        switch(n){
            case 0:
            case 1:
                return 0;
            default:
                break;
        }
        vector<int> dic(n, 1);
        int res = n - 2;
        dic[0] = 0;
        dic[1] = 0;
        for(int i = 2; i * i < n; i++){
            if(dic[i] == 0) continue;
            else{
                for(int j = i; j * i < n; j++){
                    if(dic[i * j] == 1){
                        dic[i * j] = 0;
                        res--;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

