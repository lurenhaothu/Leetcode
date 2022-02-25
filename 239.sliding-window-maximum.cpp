/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
//#include <vector>
//#include <set>
//using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        for(int i = 0; i < k; i++){
            if(q.empty()) q.push_back(nums[i]);
            else{
                while(!q.empty() && q.back() < nums[i]) q.pop_back();
                q.push_back(nums[i]);
            }
        }
        vector<int> res;
        res.push_back(q.front());
        for(int i = k; i < nums.size(); i++){
            //i is the next end point
            if(nums[i - k] == q.front()) q.pop_front();
            while(!q.empty() && q.back() < nums[i]) q.pop_back();
            q.push_back(nums[i]);
            res.push_back(q.front());
        }
        return res;
    }
};
// @lc code=end

