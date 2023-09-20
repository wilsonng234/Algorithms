#include <iostream>
#include <vector>
#include <cassert>

namespace dynamic_programming
{
    namespace max_subarray
    {
        int MaxSubarray(const std::vector<int> &arr)
        {
            /*
                values is a vector that stores the max sum of contiguous subarray ending at index i

                - values[0] = arr[0]
                - values[i] = max(arr[i], arr[i]+values[i-1])   // max(non-contiguous, contiguous)
            */

            int max_sum = arr[0];
            std::vector<int> values{arr[0]};

            for (int i = 1; i < arr.size(); i++)
            {
                values.push_back(std::max(arr[i], arr[i] + values[i - 1]));
                max_sum = std::max(max_sum, values[i]);
            }

            return max_sum;
        }

        void Test()
        {
            std::vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
            assert(MaxSubarray(arr) == 6);

            arr = {1};
            assert(MaxSubarray(arr) == 1);

            arr = {-1};
            assert(MaxSubarray(arr) == -1);

            arr = {20, 3};
            assert(MaxSubarray(arr) == 23);

            arr = {5, 4, -1, 7, 8};
            assert(MaxSubarray(arr) == 23);

            std::cout << "All tests passed" << std::endl;
        }
    }
}
