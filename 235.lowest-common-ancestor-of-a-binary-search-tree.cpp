/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int rv = root->val, pv = max(p->val, q->val), qv = min(p->val, q->val);
        if(rv == pv || rv == qv) return root;
        else if(rv < pv && rv > qv) return root;
        else if(rv > pv && rv > qv) return lowestCommonAncestor(root->left, p, q);
        else if(rv < pv && rv < qv) return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};
// @lc code=end

