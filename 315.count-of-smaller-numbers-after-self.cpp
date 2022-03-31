/*
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
 */

// @lc code=start
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n, 0);
        int low = nums[0], high = nums[0];
        for(auto i : nums){
            low = min(low, i);
            high = max(high, i);
        }
        int size = high - low + 1;
        int offset = low - 1;
        vector<int> bit(size + 1, 0);
        for(int i = n - 2; i >= 0; i--){
            addnum(bit, nums[i + 1] - offset, size);
            count[i] = getcount(bit, nums[i] - offset, size);
        }
        return count;
    }
    void addnum(vector<int>& tree, int add, int size){
        for(int i = add; i <= size; i += (i & (-i))){
            tree[i]++;
        }
    }
    int getcount(vector<int>& tree, int num, int size){
        int sum = 0;
        for(int i = num - 1; i > 0; i -= (i & (-i))){
            sum += tree[i];
        }
        return sum;
    }
};
// @lc code=end

