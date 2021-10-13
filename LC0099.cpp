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
    vector<int> inorderNum;
    int n1, n2, n3;
    void recoverTree(TreeNode* root) {
        n3 = 0;
        inorder(root);
        for(int i = 0; i < inorderNum.size() - 1; i++){
            if(inorderNum[i] > inorderNum[i + 1]){
                n3++;
                if(n3 == 1){
                    n1 = inorderNum[i];
                    n2 = inorderNum[i + 1];
                }else if(n3 == 2) n2 = inorderNum[i + 1];
            }
        }
        inorder(root);
        return;
    }
    
    void inorder(TreeNode* root){
        if(root->left){
            inorder(root->left);
        }
        if(n3 == 0) inorderNum.push_back(root->val);
        else{
            if(root->val == n1) root->val = n2;
            else if(root->val == n2) root->val = n1;
        }
        if(root->right){
            inorder(root->right);
        }
        return;
    }
};
