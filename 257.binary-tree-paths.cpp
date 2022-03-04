/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string path;
        DFS(res, path, root);
        return res;
    }
    void DFS(vector<string> &res, string &path, TreeNode* root){
        //root is not visited yet
        int n = path.length();
        if(!path.empty())path = path + "->" + to_string(root->val);
        else path = path + to_string(root->val);
        if(root->left) DFS(res, path, root->left);
        if(root->right) DFS(res, path, root->right);
        if(!root->left && !root->right) res.push_back(path);
        path.erase(n, path.length() - n);
        return;
    }
};
// @lc code=end

