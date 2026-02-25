class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int maxprofit = 0;
        for(int i = 1 ; i < prices.size() ; i++){
            buy = min(buy , prices[i]);
            int sell = prices[i];
            int profit = sell - buy;
            maxprofit = max(maxprofit , profit);
        }
        return maxprofit;
    }
};