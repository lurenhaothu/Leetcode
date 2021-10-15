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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 1) return new TreeNode(inorder[0]);
        int indp = inorder.size() - 2, indi = inorder.size() - 1;
        stack<TreeNode*> st;
        st.push(new TreeNode(postorder.back()));
        TreeNode *res = st.top(), *lastpop, *temp;
        while(indp >= 0){
            while(st.top()->val != inorder[indi]){
                temp = new TreeNode(postorder[indp]);
                st.top()->right = temp;
                st.push(temp);
                indp--;
            }
            while(st.top()->val == inorder[indi]){
                lastpop = st.top();
                st.pop();
                indi--;
                if(st.empty()) break;
            }
            if(indi == -1) break;
            st.push(new TreeNode(postorder[indp]));
            lastpop->left = st.top();
            indp--;
        }
        return res;
    }
};
