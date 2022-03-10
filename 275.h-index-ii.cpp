/*
 * @lc app=leetcode id=275 lang=cpp
 *
 * [275] H-Index II
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if(n <= citations[0]) return n;
        int start = 0, end = n - 1, pivot;
        citations.push_back(INT_MAX);
        while(!(end >= citations[n - end - 1] && end <= citations[n - end])){
            pivot = (start + end) / 2 + 1;
            if(pivot >= citations[n - pivot - 1] && pivot <= citations[n - pivot]){
                start = pivot;
            }else if(pivot < citations[n - pivot - 1]){
                start = pivot + 1;
            }else if(pivot > citations[n - pivot]){
                end = pivot - 1;
            }
        }
        return end;
    }
};
// @lc code=end

