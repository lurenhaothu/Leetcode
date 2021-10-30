class Solution {
public:
    int gcd(int p, int q){
        return q ? gcd(q, p%q) : p;
    }
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n <= 2) return n;
        int maxl = 1;
        for(int i = 0; i < n - 1; i++){
            unordered_map<int, int> dic;
            for(int j = i + 1; j < n; j++){
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                if(dx == 0){
                    dic[1]++;
                    maxl = max(maxl, dic[1]);
                }else if(dy == 0){
                    dic[2e4 + 1]++;
                    maxl = max(maxl, dic[2e4 + 1]);
                }else{
                    int g = gcd(abs(dx), abs(dy));
                    if(dx < 0){dx = -dx; dy = -dy;}
                    dx /= g;
                    dy /= g;
                    dic[dx * (2e4 + 1) + dy]++;
                    maxl = max(maxl, dic[dx * (2e4 + 1) + dy]);
                }
            }
        }
        return maxl + 1;
    }
};
