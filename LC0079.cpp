class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> searched(board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word.back()){
                    searched[i][j] = true;
                    word.pop_back();
                    if(DFS(board, searched, word, i, j)) return true;
                    word += board[i][j];
                    searched[i][j] = false;
                }
            }
        }
        return false;
    }
    bool DFS(vector<vector<char>>& board, vector<vector<bool>>& searched, string word, int i, int j){
        //cout<<i<<j<<endl;
        if(word.length() == 0) return true;
        if(i - 1 >= 0){
            if(board[i - 1][j] == word.back() && !searched[i - 1][j]){
                searched[i - 1][j] = true;
                word.pop_back();
                if(DFS(board, searched, word, i - 1, j)){
                    return true;
                }
                word += board[i - 1][j];
                searched[i - 1][j] = false;
            }
        }
        if(i + 1 < board.size()){
            if(board[i + 1][j] == word.back() && !searched[i + 1][j]){
                searched[i + 1][j] = true;
                word.pop_back();
                if(DFS(board, searched, word, i + 1, j)){
                    return true;
                }
                word += board[i + 1][j];
                searched[i + 1][j] = false;
            }
        }
        if(j - 1 >= 0){
            if(board[i][j - 1] == word.back() && !searched[i][j - 1]){
                searched[i][j - 1] = true;
                word.pop_back();
                if(DFS(board, searched, word, i, j - 1)){
                    return true;
                }
                word += board[i][j - 1];
                searched[i][j - 1] = false;
            }
        }
        if(j + 1 < board[0].size()){
            if(board[i][j + 1] == word.back() && !searched[i][j + 1]){
                searched[i][j + 1] = true;
                word.pop_back();
                if(DFS(board, searched, word, i, j + 1)){
                    return true;
                }
                word += board[i][j + 1];
                searched[i][j + 1] = false;
            }
        }
        return false;
    }
};
