class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal(1, {1});
        for(int i = 1; i < numRows; i++){
            pascal.push_back({1});
            for(int j = 1; j < pascal[i - 1].size(); j++){
                pascal.back().push_back(pascal[i - 1][j - 1] + pascal[i - 1][j]);
            }
            pascal.back().push_back(1);
        }
        return pascal;
    }
};
