#include <iostream>
#include <vector>
#include <cassert>

#include "max_subarray.cpp"

namespace dynamic_programming
{
    namespace max_stock_profit
    {
        int MaxStockProfit(const std::vector<int> &prices)
        {
            if (prices.size() <= 1)
                return 0;

            std::vector<int> profit;
            for (int i = 1; i < prices.size(); i++)
                profit.push_back(prices[i] - prices[i - 1]);

            int max_profit = dynamic_programming::max_subarray::MaxSubarray(profit);
            return std::max(max_profit, 0);
        }

        void Test()
        {
            std::vector<int> prices = {7, 1, 5, 3, 6, 4};
            assert(MaxStockProfit(prices) == 5);

            prices = {1};
            assert(MaxStockProfit(prices) == 0);

            prices = {1, 2};
            assert(MaxStockProfit(prices) == 1);

            prices = {2, 1};
            assert(MaxStockProfit(prices) == 0);

            prices = {2, 1, 2, 1, 0, 1, 2};
            assert(MaxStockProfit(prices) == 2);

            std::cout << "All tests passed" << std::endl;
        }
    }
}
