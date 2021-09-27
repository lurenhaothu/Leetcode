class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(9, vector<int>(9, 0));
        vector<vector<int>> column(9, vector<int>(9, 0));
        vector<vector<int>> subbox(9, vector<int>(9, 0));
        int num;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.'){
                    continue;
                }else{
                    num = (int)board[i][j] - 49;
                    row[i][num]++;
                    column[j][num]++;
                    subbox[i / 3 * 3 + j / 3][num]++;
                    if(row[i][num] > 1 || column[j][num] > 1 || subbox[i / 3 * 3 + j / 3][num] > 1){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
