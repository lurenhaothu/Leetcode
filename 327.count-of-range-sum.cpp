/*
 * @lc app=leetcode id=327 lang=cpp
 *
 * [327] Count of Range Sum
 */

// @lc code=start
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        long long sum = 0;
        map<long long, pair<int, int>> dict;
        for(auto i : nums){
            sum += i;
            if(dict.find(sum) == dict.end()){
                dict[sum] = make_pair(1, 0);
            }else{
                dict[sum].first++;
            }
        }
        int m = dict.size();
        vector<int> bit(m + 1, 0);
        int index = 1; 
        //cout<<"sadasd"<<endl;
        for(auto& j : dict){
            update(bit, j.second.first, index);
            j.second.second = index;
            index++;
        }
        //cout<<"sadasd"<<endl;
        sum = 0;
        int res = count(dict, bit, lower, upper);
        //cout<<dict[-6].first<<endl;
        for(int j = 0; j < n - 1; j++){
            int i = nums[j];
            sum += i;
            //cout<<res<<endl;
            update(bit, -1, dict[sum].second);
            res += count(dict, bit, (long long)lower + sum, (long long)upper + sum);
        }
        return res;
    }
    int count(map<long long, pair<int, int>>& dict, vector<int> &bit, long long lower, long long upper){
        auto itr1 = dict.lower_bound(lower);
        auto itr2 = dict.lower_bound(upper);
        int lowsum, highsum;
        if(itr1 == dict.end()){
            lowsum = sum1(bit, bit.size() - 1);
        }else{
            int lowindex = itr1->second.second - 1;
            if(lowindex == 0) lowsum = 0;
            else lowsum = sum1(bit, lowindex);
        }
        if(itr2 == dict.end()){
            highsum = sum1(bit, bit.size() - 1);
        }else if(itr2->first > upper){
            int highindex = itr2->second.second - 1;
            if(highsum == 0) lowsum = 0;
            else highsum = sum1(bit, highindex);
        }else if(itr2->first == upper){
            int highindex = itr2->second.second;
            highsum = sum1(bit, highindex);
        }
        //cout<<highsum<<lowsum<<endl;
        return highsum - lowsum;
    }
    void update(vector<int> &bit, int dif, int i){
        int m = bit.size();
        for(;i < m; i += (i & (-i))){
            bit[i] += dif;
        }
    }
    int sum1(vector<int> &bit, int i){
        int m = bit.size();
        int res = 0;
        for(;i > 0; i -= (i & (-i))){
            res += bit[i];
        }
        return res;
    }
};
// @lc code=end

