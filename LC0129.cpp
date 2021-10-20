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
    int res;
    int sumNumbers(TreeNode* root) {
        res = 0;
        DFS(root, 0);
        return res;
    }
    void DFS(TreeNode* node, int cur){
        cur = cur * 10 + node->val;
        if(!node->left && !node->right){
            res += cur;
        }else{
            if(node->left) DFS(node->left, cur);
            if(node->right) DFS(node->right, cur);
        }
        return;
    }
};
