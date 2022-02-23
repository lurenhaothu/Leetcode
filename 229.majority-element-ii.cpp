/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //Boyer-moore voting algorithm
        int cand1 = 0, cnt1 = 0;
        int cand2 = 0, cnt2 = 0;
        for(auto i : nums){
            if(cand1 == i){
                cnt1++;
            }else if(cand2 == i){
                cnt2++;
            }else if(cnt1 * cnt2 == 0){
                //initializing
                if(cnt1 == 0){
                    cand1 = i;
                    cnt1 = 1;
                }else{
                    cand2 = i;
                    cnt2 = 1;
                }
            }else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0;
        cnt2 = 0;
        for(int i : nums){
            if(i == cand1) cnt1++;
            else if(i == cand2) cnt2++;
        }
        vector<int> res;
        if(cnt1 * 3 > nums.size()) res.push_back(cand1);
        if(cnt2 * 3 > nums.size() && cand1 != cand2) res.push_back(cand2);
        return res;
    }
};
/*
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //using hash mao would be too easy, lets do something fun
        //with divide and conquer
        vector<int> r = dq(nums, 0, nums.size() - 1);
        vector<int> res;
        for(int i = 0; i < r.size(); i += 2){
            res.push_back(r[i]);
        }
        return res;
    }

    vector<int> dq(vector<int>& nums, int start, int end){
        //start and end is inclusive
        if(end - start == 1){
            if(nums[start] != nums[end])
                return {nums[start], 1, nums[end], 1};
            else if(nums[start] == nums[end])
                return {nums[start], 2};
        }
        else if(end == start) return {nums[start], 1};
        int mid = (start + end) / 2;
        vector<int> cond1 = dq(nums, start, mid);
        vector<int> cond2 = dq(nums, mid + 1, end);
        int n = end - start + 1;
        vector<int> res;
        while(!cond1.empty()){
            int amount = cond1.back();
            cond1.pop_back();
            int num = cond1.back();
            cond1.pop_back();
            for(int i = mid + 1; i <= end; i++){
                if(nums[i] == num) amount++;
            }
            if(amount * 3 > n){
                res.push_back(num);
                res.push_back(amount);
            }
        }
        if(res.size() == 4) return res;
        while(!cond2.empty()){
            int amount = cond2.back();
            cond2.pop_back();
            int num = cond2.back();
            cond2.pop_back();
            if(!res.empty() && num == res[0]) continue;
            for(int i = start; i <= mid; i++){
                if(nums[i] == num) amount++;
            }
            if(amount * 3 > n){
                res.push_back(num);
                res.push_back(amount);
            }
        }
        return res;
    }
};*/
// @lc code=end

