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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        queue<TreeNode*> qads;
        queue<int> qint;
        qads.push(root);
        qint.push(targetSum);
        if(qint.back() == qads.back()->val && !qads.back()->left && !qads.back()->right) return true;
        while(!qads.empty()){
            int n = qads.size();
            for(int i = 0 ; i < n; i++){
                if(qads.front()->left){
                    qads.push(qads.front()->left);
                    qint.push(qint.front() - qads.front()->val);
                    if(qint.back() == qads.back()->val && !qads.back()->left && !qads.back()->right) return true;
                }
                if(qads.front()->right){
                    qads.push(qads.front()->right);
                    qint.push(qint.front() - qads.front()->val);
                    if(qint.back() == qads.back()->val && !qads.back()->left && !qads.back()->right) return true;
                    
                }
                qads.pop();
                qint.pop();
            }
        }
        return false;
    }
};
