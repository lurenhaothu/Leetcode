/*
 * @lc app=leetcode id=337 lang=cpp
 *
 * [337] House Robber III
 */

// @lc code=start
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
    unordered_map<TreeNode*, int> dict;
public:
    int rob(TreeNode* root) {
        if(!root) return 0;
        if(dict.find(root) != dict.end()) return dict[root];
        int res1 = rob(root->left) + rob(root->right);
        int res2 = root->val + 
            (root->left ? (rob(root->left->left) + rob(root->left->right)) : 0) + 
            (root->right ? (rob(root->right->left) + rob(root->right->right)) : 0);
        dict[root] = max(res1, res2);
        return max(res1, res2);
    }
};
// @lc code=end

