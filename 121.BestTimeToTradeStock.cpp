#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProfit(const std::vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices) {
            if (price < minPrice) {
                minPrice = price;
            } else {
                maxProfit = std::max(maxProfit, price - minPrice);
            }
        }

        return maxProfit;
    }
};
