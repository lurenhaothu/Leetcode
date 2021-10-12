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
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<vector<TreeNode*>>> OPT(n, vector<vector<TreeNode*>>(n, vector<TreeNode*>{}));
        for(int l = 1; l <= n; l++){//length
            for(int i = 1; i <= n + 1 - l; i++){//start point
                //it should be OPT[i - 1][i + l - 2]
                if(l == 1){
                    OPT[i - 1][i + l - 2].push_back(new TreeNode(i));
                }else{
                    for(int j = i; j <= i + l - 1; j++){
                        
                    }
                }
            }
        }
        return OPT[0][0];
    }
};
