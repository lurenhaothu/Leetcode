class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 1) return 0;
        vector<int> buy(prices.size() - 1);
        int profit = (prices[1] - prices[0]) > 0 ? (prices[1] - prices[0]) : 0;
        buy[0] = prices[0];
        for(int i = 1; i < prices.size() - 1; i++){
            buy[i] = buy[i - 1] > prices[i] ? prices[i] : buy[i - 1];
            profit = profit > (prices[i + 1] - buy[i]) ? profit : (prices[i + 1] - buy[i]);
        }
        return profit;
    }
};
