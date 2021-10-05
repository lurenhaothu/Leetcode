class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        bool first = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    if(j == 0){ 
                        first = true;
                        matrix[i][0] = 0;
                    }else{
                        matrix[0][j] = 0;
                        matrix[i][0] = 0;
                    }
                }
            }
        }
        for(int i = 1; i < n; i++){
            if(matrix[i][0] == 0){
                for(int k = 1; k < m; k++){
                    matrix[i][k] = 0;
                }
            }
        }
        for(int j = 1; j < m; j++){
            if(matrix[0][j] == 0){
                for(int k = 1; k < n; k++){
                    matrix[k][j] = 0;
                }
            }
        }
        if(matrix[0][0] == 0){
            for(int k = 1; k < m; k++){
                matrix[0][k] = 0;
            }
        }
        if(first){
            for(int k = 0; k < n; k++){
                matrix[k][0] = 0;
            }
        }
        return;
    }
};
