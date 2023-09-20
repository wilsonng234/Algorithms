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
            std::vector<int> prices = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
            assert(MaxStockProfit(prices) == 6);

            prices = {1};
            assert(MaxStockProfit(prices) == 1);

            prices = {-1};
            assert(MaxStockProfit(prices) == -1);

            prices = {20, 3};
            assert(MaxStockProfit(prices) == 23);

            prices = {5, 4, -1, 7, 8};
            assert(MaxStockProfit(prices) == 23);

            std::cout << "All tests passed" << std::endl;
        }
    }
}

int main()
{
    dynamic_programming::max_stock_profit::Test();
    return 0;
}