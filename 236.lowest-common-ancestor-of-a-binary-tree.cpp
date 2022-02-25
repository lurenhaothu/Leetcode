/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
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
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p == root || q == root) return root;
        vector<TreeNode*> path1, path2, temp;
        DFS(path1, temp, root, p);
        temp.clear();
        DFS(path2, temp, root, q);
        TreeNode* res;
        //for(auto i : path1) cout<<i->val;
        for(int i = 0; i < min(path1.size(), path2.size()); i++){
            if(path1[i] == path2[i]) res = path1[i];
            else break;
        }
        return res;
    }
    void DFS(vector<TreeNode*> &path, vector<TreeNode*> &temp, TreeNode* root, TreeNode* p){
        //temp include all the node that has been visited
        if(!root) return;
        else if(root == p){
            temp.push_back(p);
            path = temp;
            temp.pop_back();
            return;
        }else{
            temp.push_back(root);
            if(path.empty()) DFS(path, temp, root->left, p);
            if(path.empty()) DFS(path, temp, root->right, p);
            temp.pop_back();
            return;
        }
        return;
    }
};
// @lc code=end

