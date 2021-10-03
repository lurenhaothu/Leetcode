class Solution {
public:
    int uniquePaths(int m, int n) {
        double res = 1;
        int min = m < n ? m : n;
        for(int i = 0; i < min - 1; i++){
            res = res * (m + n - 2 - i) / (min - 1 - i);
        }
        return round(res);
    }
};
