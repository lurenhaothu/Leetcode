/*
 * @lc app=leetcode id=321 lang=cpp
 *
 * [321] Create Maximum Number
 */

// @lc code=start
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> res;
        for(int l = 0; l <= k; l++){
            update(res, sub(nums1, l), sub(nums2, k - l), k);
        }
        return res;
    }
    vector<int> sub(vector<int>& nums, int l){
        if(l > nums.size()) return {};
        int n = nums.size();
        vector<int> res;
        int popnum = 0;
        for(auto i : nums){
            if(res.empty()){
                res.push_back(i);
            }else{
                while(!res.empty() && res.back() < i && popnum < n - l){
                    res.pop_back();
                    popnum++;
                }
                res.push_back(i);
            }
        }
        while(res.size() > l) res.pop_back();
        return res;
    }
    void update(vector<int>&res, vector<int> sub1, vector<int> sub2, int k){
        if(sub1.size() + sub2.size() != k) return;
        vector<int> newres;
        int i = 0, j = 0;
        while(i < sub1.size() || j < sub2.size()){
            int ci = i < sub1.size() ? sub1[i] : -1;
            int cj = j < sub2.size() ? sub2[j] : -1;
            if(ci > cj){
                newres.push_back(ci);
                i++;
            }else if(ci < cj){
                newres.push_back(cj);
                j++;
            }else{
                //equal
                bool comp = compare(sub1, sub2, i, j);
                if(comp) {newres.push_back(ci);i++;}
                else {newres.push_back(cj);j++;}
            }
        }
        bool comp2 = compare(res, newres, 0, 0);
        if(!comp2) res.swap(newres);
        return;
    }
    bool compare(vector<int>& sub1, vector<int>& sub2, int i, int j){
        while(i < sub1.size() && j < sub2.size() && sub1[i] == sub2[j]){i++; j++;}
        if(i == sub1.size()) return false;
        else if(j == sub2.size()) return true;
        else return sub1[i] > sub2[j];
    }
};
// @lc code=end

