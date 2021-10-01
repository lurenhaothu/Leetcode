class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        //vector<int> direct{0, 1, 2, 3};//right, down, left, up
        vector<int> res;
        int curdir = 0, curi = 0, curj = 0;
        while(res.size() != n * m){
            res.push_back(matrix[curi][curj]);
            matrix[curi][curj] = -101;
            if(curdir == 0){
                if(curj + 1 < m){
                    if(matrix[curi][curj + 1] == -101){
                        curdir = 1;
                        curi++;
                    }else{
                        curj++;
                    }
                }else{
                    curdir = 1;
                    curi++;
                }
            }else if(curdir == 1){
                if(curi + 1 < n){
                    if(matrix[curi + 1][curj] == -101){
                        curdir = 2;
                        curj--;
                    }else{
                        curi++;
                    }
                }else{
                    curdir = 2;
                    curj--;
                }
            }else if(curdir == 2){
                if(curj - 1 >= 0){
                    if(matrix[curi][curj - 1] == -101){
                        curdir = 3;
                        curi--;
                    }else{
                        curj--;
                    }
                }else{
                    curdir = 3;
                    curi--;
                }
            }else if(curdir == 3){
                if(curi - 1 >= 0){
                    if(matrix[curi - 1][curj] == -101){
                        curdir = 0;
                        curj++;
                    }else{
                        curi--;
                    }
                }else{
                    curdir = 0;
                    curj++;
                }
            }
        }
        return res;
    }
};
