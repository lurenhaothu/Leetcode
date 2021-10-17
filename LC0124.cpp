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
    int maxSum;//cannot be connected upward
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        int max2 = maxP(root);
        return max(maxSum, max2);
    }
    int maxP(TreeNode* root) {//return that can be connected upward
        if(!root) return INT_MIN;
        if(!root->left && !root->right) return root->val;
        int left1 = maxP(root->left);
        int right1 = maxP(root->right);
        maxSum = max(maxSum, max(left1, right1));
        maxSum = max(maxSum, root->val + max(left1, 0) + max(right1, 0));
        return root->val + max(max(right1, left1), 0);
    }
};
