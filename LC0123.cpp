class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> OPT1(n, 0), OPT2(n, 0);
        int minibuy = prices[0], maxsell = prices.back();
        for(int i = 1; i < n; i++){
            minibuy = min(minibuy, prices[i - 1]);
            OPT1[i] = max(prices[i] - minibuy, OPT1[i - 1]);
            //cout<<OPT1[i];
        }
        //cout<<endl;
        for(int i = n - 2; i >= 0; i--){
            maxsell = max(maxsell, prices[i + 1]);
            OPT2[i] = max(maxsell - prices[i], OPT2[i + 1]);
            //cout<<OPT2[i];
        }
        int maxprofit = OPT1[n - 1];
        for(int i = 1; i <= n - 2; i++){
            maxprofit = max(maxprofit, OPT1[i] + OPT2[i + 1]);
        }
        return maxprofit;
    }
};
