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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        else if((p && !q) || (!p && q)) return false;
        if(p->val != q->val) return false;
        if(p->left && q->left){
            if(!isSameTree(p->left, q->left)) return false;
        }else if((p->left && !q->left) || (!p->left && q->left)) return false;
        if(p->right && q->right){
            if(!isSameTree(p->right, q->right)) return false;
        }else if((p->right && !q->right) || (!p->right && q->right)) return false;
        return true;
    }
};
