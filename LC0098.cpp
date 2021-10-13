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
    bool isValidBST(TreeNode* root) {
        TreeNode* p;
        if(root->left){
            if(root->left->val >= root->val) return false;
            if(!isValidBST(root->left)) return false;
            p = root->left;
            while(p->right){
                p = p->right;
            }
            if(p->val >= root->val) return false;
        }
        if(root->right){
            if(root->right->val <= root->val) return false;
            if(!isValidBST(root->right)) return false;
            p = root->right;
            while(p->left){
                p = p->left;
            }
            if(p->val <= root->val) return false;
        }
        return true;
    }
};
