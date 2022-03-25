/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            if(cur){
                res += to_string(cur->val);
                q.push(cur->left);
                q.push(cur->right);
            }
            else res += to_string(-10000);
            res += " ";
        }
        /*stringstream is(res);
        int i;
        is >> i;
        cout<<i;*/
        //cout<<res;
        return res; 
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;
        stringstream is(data);
        int input;
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(0);
        q.push(root);
        is >> input;
        root->val = input;
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            is>>input;
            if(input != -10000){
                cur->left = new TreeNode(input);
                q.push(cur->left);
            }
            is>>input;
            if(input != -10000){
                cur->right = new TreeNode(input);
                q.push(cur->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

