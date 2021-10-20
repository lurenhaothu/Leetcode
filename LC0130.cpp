class Solution {
public:
    int m, n;
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        if(m == 1 || n == 1) return;
        //vector<vector<bool>> safe(m, vector<bool>(n, false));
        for(int i = 0; i < n; i++){
            if(board[0][i] == 'O') expolresave(board, 0, i);
            if(board[m - 1][i] == 'O') expolresave(board, m - 1, i);
        }
        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O') expolresave(board, i, 0);
            if(board[i][n - 1] == 'O') expolresave(board, i, n - 1);
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == 'A') board[i][j] = 'O';
            }
        }
        return;
    }
    void expolresave(vector<vector<char>>& board, int i, int j){
        if(board[i][j] == 'A') return;
        board[i][j] = 'A';
        queue<vector<int>> q;
        q.push({i, j});
        int k, t;
        while(!q.empty()){
            k = q.front()[0];
            t = q.front()[1];
            q.pop();
            if(k - 1 >= 0 && board[k - 1][t] == 'O'){
                board[k - 1][t] = 'A';
                q.push({k - 1, t});
            }
            if(t - 1 >= 0 && board[k][t - 1] == 'O'){
                board[k][t - 1] = 'A';
                q.push({k, t - 1});
            }
            if(k + 1 < m && board[k + 1][t] == 'O'){
                board[k + 1][t] = 'A';
                q.push({k + 1, t});
            }
            if(t + 1 < n && board[k][t + 1] == 'O'){
                board[k][t + 1] = 'A';
                q.push({k, t + 1});
            }
        }
        return;
    }
};
