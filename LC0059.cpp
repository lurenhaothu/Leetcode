class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int m = n, i = 1;
        //vector<int> direct{0, 1, 2, 3};//right, down, left, up
        int curdir = 0, curi = 0, curj = 0;
        while(i <= n * n){
            matrix[curi][curj] = i;
            i++;
            if(curdir == 0){
                if(curj + 1 < m){
                    if(matrix[curi][curj + 1] != 0){
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
                    if(matrix[curi + 1][curj] != 0){
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
                    if(matrix[curi][curj - 1] != 0){
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
                    if(matrix[curi - 1][curj] != 0){
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
        return matrix;
    }
};
