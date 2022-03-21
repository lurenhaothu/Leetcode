class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        int maxscore = 0;
        vector<int> log, res;
        DFS(0, numArrows, aliceArrows, 11, maxscore, log, res);
        while(res.size() < 12) res.push_back(0);
        reverse(res.begin(), res.end());
        return res;
    }
    void DFS(int score, int rem, vector<int>& aliceArrows, int next, int& maxscore, vector<int>& log, vector<int>& res){
        if(next == 0){
            if(rem != 0) log.push_back(rem);
            if(score > maxscore){
                res = log;
                maxscore = score;
            }
            if(rem != 0) log.pop_back();
            return;
        }
        if(rem >= aliceArrows[next] + 1){
            log.push_back(aliceArrows[next] + 1);
            DFS(score + next, rem - aliceArrows[next] - 1, aliceArrows, next - 1, maxscore, log, res);
            log.back() = 0;
            DFS(score, rem, aliceArrows, next - 1, maxscore, log, res);
            log.pop_back();
        }else{
            log.push_back(0);
            DFS(score, rem, aliceArrows, next - 1, maxscore, log, res);
            log.pop_back();
        }
    }
};
