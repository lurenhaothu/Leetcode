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
    bool isBalanced(TreeNode* root) {
        return (depth(root) != -1);
    }
    int depth(TreeNode* root){
        if(!root) return 0;
        int a = depth(root->left);
        int b = depth(root->right);
        if(a == -1 || b == -1 || abs(a - b) > 1) return -1;
        else return 1 + max(a, b);
    }
};
