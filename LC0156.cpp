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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(!root) return NULL;
        stack<TreeNode*> st;
        TreeNode* pr = root;
        while(pr->left){
            st.push(pr);
            pr = pr->left;
        }
        assert(pr);
        assert(!pr->left);
        TreeNode *r = pr;
        while(!st.empty()){
            pr->right = st.top();
            pr->left = st.top()->right;
            pr = st.top();
            st.pop();
        }
        pr->right = NULL;
        pr->left = NULL;
        return r;
    }
};
