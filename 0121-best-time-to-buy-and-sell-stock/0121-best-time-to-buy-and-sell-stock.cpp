class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_prices = prices[0];
        int profit = 0;
        for(int i = 0; i < prices.size(); i++){
            min_prices = min(min_prices, prices[i]);
            profit = max(profit, prices[i] - min_prices);
        }
        return profit;
    }
};