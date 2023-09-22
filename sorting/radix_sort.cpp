#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

namespace sorting
{
    namespace radix_sort
    {
        void CountingSort(std::vector<int> &arr, int exp)
        {
            std::vector<int> counter(10, 0);
            std::vector<int> output(arr.size(), 0);

            for (int num : arr)
                counter[(num / exp) % 10]++;
            for (int i = 1; i < 10; i++)
                counter[i] += counter[i - 1];

            for (int i = arr.size() - 1; i >= 0; i--)
            {
                output[counter[(arr[i] / exp) % 10] - 1] = arr[i];
                counter[(arr[i] / exp) % 10]--;
            }

            arr = output;
        }

        void RadixSort(std::vector<int> &arr)
        {
            int max = *std::max_element(arr.begin(), arr.end());

            for (int exp = 1; max / exp > 0; exp *= 10)
                CountingSort(arr, exp);
        }

        void Test()
        {
            std::vector<int> arr = {5, 2, 4, 6, 1, 3};
            RadixSort(arr);

            assert(arr == std::vector<int>({1, 2, 3, 4, 5, 6}));
            std::cout << "All tests passed" << std::endl;
        }
    }
}
