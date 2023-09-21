#include <iostream>
#include <vector>
#include <cassert>

namespace randomized_algorithm
{
    namespace quick_select
    {
        int Partition(std::vector<int> &arr, int start, int end)
        {
            // Select pivot and swap pivot to the end position
            std::swap(arr[rand() % (end - start + 1) + start], arr[end]);
            int pivot = arr[end];

            for (int i = start; i < end; i++)
            {
                if (arr[i] <= pivot)
                {
                    std::swap(arr[i], arr[start]);
                    start++;
                }
            }

            std::swap(arr[start], arr[end]);
            return start;
        }

        int QuickSelect(std::vector<int> &arr, int k, int start, int end);

        // return the kth smallest element in arr
        int QuickSelect(std::vector<int> &arr, int k)
        {
            if (k <= 0)
                throw std::invalid_argument("k must be positive");
            if (k > arr.size())
                throw std::invalid_argument("k is larger than the size of arr");

            srand(time(NULL));
            return QuickSelect(arr, k, 0, arr.size() - 1);
        }

        int QuickSelect(std::vector<int> &arr, int k, int start, int end)
        {
            int pivot_idx = Partition(arr, start, end);

            if (pivot_idx == start + k - 1)
                return arr[pivot_idx];
            else if (pivot_idx < start + k - 1)
                return QuickSelect(arr, k - (pivot_idx - start + 1), pivot_idx + 1, end);
            else
                return QuickSelect(arr, k, start, pivot_idx - 1);
        }

        void Test()
        {
            std::vector<int> arr = {5, -2, 4, -6, 1, 3};
            assert(QuickSelect(arr, 1) == -6);
            assert(QuickSelect(arr, 2) == -2);
            assert(QuickSelect(arr, 3) == 1);
            assert(QuickSelect(arr, 4) == 3);
            assert(QuickSelect(arr, 5) == 4);
            assert(QuickSelect(arr, 6) == 5);

            arr = {5};
            assert(QuickSelect(arr, 1) == 5);
        }
    }
}
