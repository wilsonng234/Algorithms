#include <iostream>
#include <vector>
#include <cassert>

namespace sorting
{
    namespace counting_sort
    {
        // numbers from 0 to range
        void CountingSort(std::vector<int> &arr, int range)
        {
            std::vector<int> counter(range + 1, 0);
            std::vector<int> result(arr.size(), 0);

            for (int num : arr)
                counter[num]++;
            for (int i = 1; i <= range; i++)
                counter[i] += counter[i - 1];

            for (int i = arr.size() - 1; i >= 0; i--)
            {
                result[counter[arr[i]] - 1] = arr[i];
                counter[arr[i]]--;
            }

            arr = result;
        }

        void Test()
        {
            int range = 10000;

            std::vector<int> arr = {5, 32, 4, 0, 135, 1, 3};
            CountingSort(arr, range);
            assert(arr == std::vector<int>({0, 1, 3, 4, 5, 32, 135}));

            arr = {0, 1};
            CountingSort(arr, range);
            assert(arr == std::vector<int>({0, 1}));

            arr = {20, 0, 0, 5, 3};
            CountingSort(arr, range);
            assert(arr == std::vector<int>({0, 0, 3, 5, 20}));

            arr = {3, 20, 7};
            CountingSort(arr, range);
            assert(arr == std::vector<int>({3, 7, 20}));

            arr = {3, 20, 7, 1};
            CountingSort(arr, range);
            assert(arr == std::vector<int>({1, 3, 7, 20}));

            std::cout << "All tests passed" << std::endl;
        }
    }
}
