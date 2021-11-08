class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int result = w;
        std::priority_queue<int, std::vector<int>> available_projects;
        std::multiset<std::pair<int, int>> queued_capital_profit_pairs;
        
        // Initialization.
        for (int i = 0; i < capital.size(); ++i) {
            if (capital[i] <= result) {
                available_projects.push(profits[i]);
            } else {
                queued_capital_profit_pairs.insert(std::make_pair(capital[i], profits[i]));
            }
        }
        
        // Iteratively select projects.
        auto queue_iter = queued_capital_profit_pairs.cbegin();
        for (; !available_projects.empty() && k > 0; --k) {
            result += available_projects.top();
            available_projects.pop();
            for (; queue_iter != queued_capital_profit_pairs.cend() && queue_iter->first <= result; ++queue_iter) {
                available_projects.push(queue_iter->second); 
            }
        }
        
        return result;
    }
};
