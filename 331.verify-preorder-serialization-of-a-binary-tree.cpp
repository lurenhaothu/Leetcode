/*
 * @lc app=leetcode id=331 lang=cpp
 *
 * [331] Verify Preorder Serialization of a Binary Tree
 */

// @lc code=start
class Solution {
public:
    bool isValidSerialization(string preorder) {
        preorder+= ',';
        string seq;
        for(int i = 0; i < preorder.size(); i++){
            char j = preorder[i];
            if(j == ','){
                if(i != 0 && preorder[i - 1] == '#') continue;
                else seq += 'K';
            }else if(j == '#') seq += '#';
        }
        //cout<<seq<<endl;
        string res;
        int index = 0;
        for(auto i : seq){
            res += i;
            index = res.size() - 1;
            while(res.size() >= 3 && res[index] == '#' && res[index - 1] == '#' && res[index - 2] == 'K'){
                res.pop_back();
                res.pop_back();
                res.pop_back();
                res += '#';
                index = res.size() - 1;
            }
            //cout<<res<<endl;
        }
        return res == "#";
    }
};
// @lc code=end

