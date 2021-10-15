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
//This problem can also be solve with stack
class Solution {
public:
    vector<int> p, i;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        p = preorder;
        i = inorder;
        return(bt(0, 0, preorder.size()));
    }
    TreeNode* bt(int s1, int s2, int l){
        if(l == 0) return 0;
        int root;
        for(root = 0; root < l; root++){
            if(p[s1] == i[s2 + root]) break;
        }
        return new TreeNode(
            p[s1], 
            bt(s1 + 1, s2, root), 
            bt(s1 + root + 1, s2 + root + 1, l - 1 - root)
        );
    }
};

//Stack solution
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 1) return new TreeNode(preorder[0]);
        int indp = 1, indi = 0;
        stack<TreeNode*> st;
        st.push(new TreeNode(preorder[0]));
        TreeNode *res = st.top(), *lastpop, *temp;
        for(; indp < inorder.size(); indp++){
            if(st.top()->val != inorder[indi]){
                st.top()->left = new TreeNode(preorder[indp]);
                st.push(st.top()->left);
            }
            else{
                while(!st.empty() && st.top()->val == inorder[indi]){
                    lastpop = st.top();
                    st.pop();
                    indi++;
                }
                st.push(new TreeNode(preorder[indp]));
                lastpop->right = st.top();
            }
        }
        return res;
    }
};
