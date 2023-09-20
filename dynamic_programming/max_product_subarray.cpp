#include <iostream>
#include <vector>
#include <cassert>

namespace dynamic_programming
{
    namespace max_product_subarray
    {
        int MaxProductSubarray(const std::vector<int> &arr)
        {
            /*
                positive is a vector that stores the most positive element of contiguous subarray ending at index i
                negative is a vector that stores the most negative element of contiguous subarray ending at index i

                - positive[0] = max(0, arr[0])
                - positive[i] = max(arr[i], positive[i-1]*arr[i], negative[i-1]*arr[i])

                - negative[0] = min(0, arr[0])
                - negative[i] = min(arr[i], positive[i-1]*arr[i], negative[i-1]*arr[i])
            */

            int max_product = arr[0];
            std::vector<int> positive{std::max(0, arr[0])};
            std::vector<int> negative{std::min(0, arr[0])};

            for (int i = 1; i < arr.size(); i++)
            {
                int num = arr[i];
                int most_positive = std::max(std::max(num, positive[i - 1] * num), negative[i - 1] * num);
                int most_negative = std::min(std::min(num, positive[i - 1] * num), negative[i - 1] * num);

                positive.push_back(most_positive);
                negative.push_back(most_negative);

                max_product = std::max(max_product, most_positive);
            }

            return max_product;
        }

        void Test()
        {
            std::vector<int> arr = {2, 3, -2, 4};
            assert(MaxProductSubarray(arr) == 6);

            arr = {-2, 0, -1};
            assert(MaxProductSubarray(arr) == 0);

            arr = {-2, 3, -4};
            assert(MaxProductSubarray(arr) == 24);

            arr = {-1};
            assert(MaxProductSubarray(arr) == -1);

            std::cout << "All tests passed" << std::endl;
        }
    }
}
