/*
 * @lc app=leetcode id=307 lang=cpp
 *
 * [307] Range Sum Query - Mutable
 */

// @lc code=start
class NumArray {
    vector<int> tree;
    int n;
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree = vector<int>(2 * n, 0);
        for(int i = 0; i < n; i++) tree[i + n] = nums[i];
        for(int i = n - 1; i > 0; i--) tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
    
    void update(int index, int val) {
        index += n;
        tree[index] = val;
        while(index / 2 != 0){
            index /= 2;
            tree[index] = tree[index * 2] + tree[index * 2 + 1];
        }
        return;
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        left += n;
        right += n;
        while(left <= right){
            if(left % 2 == 1){
                sum += tree[left];
                left++;
            }
            if(right % 2 == 0){
                sum += tree[right];
                right--;
            }
            left /= 2;
            right /= 2;
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end

