class Solution {
public:
    vector<vector<int>> row;
    vector<vector<int>> column;
    vector<vector<int>> subbox;
    vector<int> I, J;
    int pr;
    bool solved = false;
    void solveSudoku(vector<vector<char>>& board){
        row = vector<vector<int>>(9, vector<int>(9, 0));
        column = vector<vector<int>>(9, vector<int>(9, 0));
        subbox = vector<vector<int>>(9, vector<int>(9, 0));
        pr = 0;
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
                }
            }
        }
        int i = 0;
        while(i < 81){
            if(board[i / 9][i % 9] == '.'){
                I.push_back(i / 9);
                J.push_back(i % 9);
                //cout<<I.size()<<endl;
            }
            i++;
        }
        solveSudokuDFS(board);
        return;
    }
    void solveSudokuDFS(vector<vector<char>>& board) {
        if(pr == I.size()){
            solved = true;
            return;
        }
        for(int num = 0; num < 9; num++){
            if(row[I[pr]][num] == 1 || 
               column[J[pr]][num] == 1 || 
               subbox[I[pr] / 3 * 3 + J[pr] / 3][num] == 1) continue;
            else{
                row[I[pr]][num]++;
                column[J[pr]][num]++;
                subbox[I[pr] / 3 * 3 + J[pr] / 3][num]++;
                board[I[pr]][J[pr]] = (char)(num + 49);
                pr++;
                solveSudokuDFS(board);
                if(solved) return;
                pr--;
                board[I[pr]][J[pr]] = '.';
                row[I[pr]][num]--;
                column[J[pr]][num]--;
                subbox[I[pr] / 3 * 3 + J[pr] / 3][num]--;
                
            }    
        }
        return;
    }
};
