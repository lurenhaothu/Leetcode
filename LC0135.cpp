class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size() == 1) return 1;
        int n = ratings.size();
        vector<int> assign(n, 0);
        int lowRate = 0, sum = 0;
        while(assign.back() == 0){
            while((lowRate == 0 && ratings[lowRate] > ratings[lowRate + 1]) ||
                 (lowRate == n - 1 && ratings[lowRate] > ratings[lowRate - 1])||
                 (lowRate > 0 && lowRate < n - 1 && (ratings[lowRate] > ratings[lowRate - 1] || ratings[lowRate] > ratings[lowRate + 1]))){
                lowRate++;
            }
            if(lowRate == n) break;
            assign[lowRate] = 1;
            for(int i = lowRate - 1; i >= 0; i--){
                if(ratings[i] > ratings[i + 1]) assign[i] = max(assign[i + 1] + 1, assign[i]); 
                else break;
            }
            for(int i = lowRate + 1; i < n; i++){
                if(ratings[i] > ratings[i - 1]) assign[i] = max(assign[i - 1] + 1, assign[i]); 
                else break;
            }
            lowRate++;
        }
        for(int i : assign){
            sum = sum + i;
            //cout<<i<<' ';
        }
        return sum;
    }
};
