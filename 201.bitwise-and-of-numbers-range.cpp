/*
 * @lc app=leetcode id=201 lang=cpp
 *
 * [201] Bitwise AND of Numbers Range
 */

// @lc code=start
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int res = 0;
        for(int i = 31; i >= 0; i--){
            //cout<<(((left >> 1) & 1) << i)<<' '<<i<<endl;;
            if( ((left >> i) & 1) == ((right >> i) & 1) ){
                res += ((left >> i) & 1) << i;
            }else break;
        }
        return res;
    }
};
// @lc code=end

