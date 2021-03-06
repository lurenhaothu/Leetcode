/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
public:
    int kthSmallest(TreeNode* root, int k) {
        int n = getsize(root->left);
        if(n >= k) return kthSmallest(root->left, k);
        else if(n == k - 1) return root->val;
        else return kthSmallest(root->right, k - 1 - n);
    }
    int getsize(TreeNode* root){
        if(!root) return 0;
        else return 1 + getsize(root->left) + getsize(root->right);
    }
};
// @lc code=end

