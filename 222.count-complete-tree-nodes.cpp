/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
 */

// @lc code=start
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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        TreeNode *ptr1 = root;
        int h = 0;
        while(ptr1->left){
            ptr1 = ptr1->left;
            h++;
        }
        //cout<<h;
        //for(int i = 0; i < pow(2, h); i++){
        //    cout<<i<<hght(h, root, i)<<endl;
        //}
        int end = pow(2, h) - 1;
        if(hght(h, root, end) == h) return pow(2, h + 1) - 1;
        int start = 0;
        int pivot;
        while(start < end){
            pivot = (start + end) / 2 + 1;
            int hp = hght(h, root, pivot);
            if(hp == h) start = pivot;
            else end = pivot - 1;
        }
        return pow(2, h) + start;
    }
    int hght(int h, TreeNode* root, int d){
        TreeNode* ptr = root;
        int h1 = 0;
        while(ptr && h1 < h){
            int dir = (d >> (h - h1 - 1)) & 1;
            h1++;
            if(dir == 0) ptr = ptr->left;
            if(dir == 1) ptr = ptr->right;
        }
        if(ptr) return h1;
        else return h1 - 1;
    }
};
// @lc code=end

