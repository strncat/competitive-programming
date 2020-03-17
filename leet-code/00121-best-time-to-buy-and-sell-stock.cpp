class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) { return 0; }

        int min = prices[0];
        int max_diff = 0;
        int n = prices.size();
        // we must buy before we sell so we track of the minimum stock price
        for (int i = 1; i < n; i++) {
            if (prices[i] - min > max_diff) {
                max_diff = prices[i] - min;
            }
            if (prices[i] < min) {
                min = prices[i];
            }
        }
        return max_diff;
    }
};