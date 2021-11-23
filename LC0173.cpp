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
class BSTIterator {
private:
    stack<TreeNode*> st;
    TreeNode* pr;

public:
    BSTIterator(TreeNode* root) {
        pr = root;
        while(pr->left){
            st.push(pr);
            pr = pr->left;
        }
        pr->left = new TreeNode(-1);
        st.push(pr);
        pr = pr->left;
        st.push(pr);
    }
    
    int next() {
        if(pr->right){
            st.pop();
            pr = pr->right;
            st.push(pr);
            while(pr->left){
                pr = pr->left;
                st.push(pr);
            }
            return pr->val;
        }else{
            st.pop();
            pr = st.top();
            return pr->val;
        }
    }
    
    bool hasNext() {
        //cout<<st.size();
        if(pr->right || st.size() > 1) return true;
        else return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
