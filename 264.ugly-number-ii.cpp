/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 */

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> cand = {1};
        for(int i = 0; i < n - 1; i++){
            cand.push_back(min(min(bsearch(cand, 2), bsearch(cand, 3)), bsearch(cand, 5)));
        }
        return cand.back();
    }
    int bsearch(vector<int> &cand, int k){
        int start = 0, end = cand.size() - 1;
        int pivot;
        while(start < end){
            pivot = (start + end) / 2;
            if((long long)cand[pivot] * k <= cand.back()) start = pivot + 1;
            else end = pivot;
        }
        return cand[start] * k;
    }
};
// @lc code=end

