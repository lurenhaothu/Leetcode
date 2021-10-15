/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return satb(nums, 0, nums.size() - 1);
    }
    TreeNode* satb(vector<int>& nums, int begin, int end) {
        if(begin > end) return nullptr;
        int mid = (begin + end) / 2;
        return new TreeNode(nums[mid], satb(nums, begin, mid - 1), satb(nums, mid + 1, end));
    }
};
