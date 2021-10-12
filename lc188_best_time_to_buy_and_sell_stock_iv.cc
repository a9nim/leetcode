class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        std::vector<std::vector<std::vector<int>>> cache(prices.size(), std::vector(2, std::vector(k + 1, -1)));    
        return maxProfitRecur(prices.size() - 1, k, 0, prices, cache);
    }
    
    int maxProfitRecur(int day, int transaction_count, int pending_buy, const std::vector<int>& prices, std::vector<std::vector<std::vector<int>>>& cache) {
        if (cache[day][pending_buy][transaction_count] != -1) {
            return cache[day][pending_buy][transaction_count];
        }
        
        int max_profit = 0;
        if (day == 0) {
            max_profit = pending_buy == 1 ? -prices[0] : 0;
        } else if (transaction_count == 0) {
            max_profit = pending_buy == 1 ? std::max(-prices[day], maxProfitRecur(day - 1, 0, 1, prices, cache)) : 0;
        } else if (pending_buy == 1) {
            max_profit = std::max(maxProfitRecur(day - 1, transaction_count, 1, prices, cache), maxProfitRecur(day - 1, transaction_count, 0, prices, cache) - prices[day]);
        } else {
            max_profit = std::max(maxProfitRecur(day - 1, transaction_count, 0, prices, cache), maxProfitRecur(day - 1, transaction_count - 1, 1, prices, cache) + prices[day]);
        }
        cache[day][pending_buy][transaction_count] = max_profit;
        return max_profit;
    } 
};
