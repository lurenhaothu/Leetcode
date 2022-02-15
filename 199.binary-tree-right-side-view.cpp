/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
    vector<int> res;
    int depth = 0;
    vector<int> rightSideView(TreeNode* root) {
        DFS(root);
        return res;
    }
    void DFS(TreeNode* p){
        if(!p) return;
        if(depth == res.size()) res.push_back(p->val);
        if(p->right){
            depth++;
            DFS(p->right);
            depth--;
        }
        if(p->left){
            depth++;
            DFS(p->left);
            depth--;
        }
        return;
    }
};
// @lc code=end

