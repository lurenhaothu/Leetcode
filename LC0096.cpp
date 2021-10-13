class Solution {
public:
    int numTrees(int n) {
        vector<int> res;
        res.push_back(1);
        for(int i = 1; i < n; i++){
            int r = 2 * res[i - 1];
            for(int j = 0; j <= i - 2; j++){
                r += res[j] * res[i - 2 - j];
            }
            res.push_back(r);
        }
        return res.back();
    }
};
