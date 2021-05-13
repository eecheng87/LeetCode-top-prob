class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 10e5, profit = -10e2;
        for(int i = 0; i < prices.size(); i++){
            buy = min(buy, prices[i]);
            profit = max(profit, prices[i] - buy);
        }
        return profit < 0 ? 0 : profit;
    }
};