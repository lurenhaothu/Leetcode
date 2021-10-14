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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<vector<TreeNode*>> lib;
        if(!root) return res;
        lib.push_back(vector<TreeNode*>{root});
        res.push_back(vector<int>{root->val});
        while(lib[lib.size() - 1].size() != 0){
            lib.push_back(vector<TreeNode*>{});
            res.push_back(vector<int>{});
            for(int i = 0; i < lib[lib.size() - 2].size(); i++){
                if(lib[lib.size() - 2][i]->left){
                    lib[lib.size() - 1].push_back(lib[lib.size() - 2][i]->left);
                    res[lib.size() - 1].push_back(lib[lib.size() - 2][i]->left->val);
                }
                if(lib[lib.size() - 2][i]->right){
                    lib[lib.size() - 1].push_back(lib[lib.size() - 2][i]->right);
                    res[lib.size() - 1].push_back(lib[lib.size() - 2][i]->right->val);
                }
            }
        }
        res.pop_back();
        return res;
    }
};
