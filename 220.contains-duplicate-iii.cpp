/*
 * @lc app=leetcode id=220 lang=cpp
 *
 * [220] Contains Duplicate III
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<long long> dic;
        int n = nums.size();
        for(int i = 1; i < n; i++){
            dic.insert(nums[i - 1]);
            if(dic.size() > k){
                auto itr = dic.find(nums[i - k - 1]);
                dic.erase(itr);
            }
            //if(dic.upper_bound(nums[i] + t) != dic.end() &&
             //   dic.lower_bound(nums[i] - t) != dic.end()) return true;
            auto itr = dic.lower_bound((long long)nums[i] - t);
            if(itr != dic.end() && *itr <= (long long)nums[i] + t) return true;
        }
        return false;
    }
};
//bucket solution
/*
class Solution {
public:
    long long getid(long long x, long long w){
        return x >= 0 ? x / w : (x + 1) / w - 1;
    }
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        unordered_map<long long, long long> dic;
        int n = nums.size();
        long long w = (long long)t + 1;
        for(int i = 0; i < n; i++){
            long long id = getid(nums[i], w);
            if(dic.find(id) != dic.end()) return true;
            else if(dic.find(id - 1) != dic.end() && abs(dic[id - 1] - nums[i]) <= t) return true;
            else if(dic.find(id + 1) != dic.end() && abs(dic[id + 1] - nums[i]) <= t) return true;
            dic[id] = nums[i];
            if(i >= k) dic.erase(getid(nums[i - k], w));
        }
        return false;
    }
};
*/
//[1,0,1,1]\n1\n2
//[1,5,9,1,5,9]\n2\n3
// @lc code=end

