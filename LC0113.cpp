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
    vector<int> record;
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return res;
        record.push_back(root->val);
        DFS(root, targetSum - record.back());
        return res;
    }
    
    void DFS(TreeNode* node, int target){
        if(!node->left && !node->right){
            if(target == 0) res.push_back(record);
            return;
        }
        if(node->left){
            record.push_back(node->left->val);
            DFS(node->left, target - record.back());
            record.pop_back();
        }
        if(node->right){
            record.push_back(node->right->val);
            DFS(node->right, target - record.back());
            record.pop_back();
        }
        return;
    }
};
