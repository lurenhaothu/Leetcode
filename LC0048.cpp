class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 1) return;
        int p, q;
        if(n % 2 == 0){
            p = n / 2;
            q = p;
        }else{
            p = n / 2;
            q = p + 1;
        }
        int t;
        for(int i = 0; i < p; i++){
            for(int j = 0; j < q; j++){
                t = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = t;
            }
        }
        return;
    }
};
