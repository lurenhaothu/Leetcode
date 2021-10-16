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
    void flatten(TreeNode* root) {
        if(!root) return;
        TreeNode *rightp = root->right, *pr = root;
        flatten(root->left);
        flatten(root->right);
        root->right = root->left;
        root->left = nullptr;
        while(pr->right) pr = pr->right;
        pr->right = rightp;
        return;
    }
};
