#include <iostream>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <ctime>

namespace sorting
{
    namespace quick_sort
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

        void QuickSort(std::vector<int> &arr, int start, int end);

        void QuickSort(std::vector<int> &arr)
        {
            srand(time(NULL));
            QuickSort(arr, 0, arr.size() - 1);
        }

        void QuickSort(std::vector<int> &arr, int start, int end)
        {
            if (start >= end)
                return;

            int pivot_idx = Partition(arr, start, end);
            QuickSort(arr, start, pivot_idx - 1);
            QuickSort(arr, pivot_idx + 1, end);
        }

        void Test()
        {
            std::vector<int> arr = {5, -2, 4, -6, 1, 3};
            QuickSort(arr);
            assert(arr == std::vector<int>({-6, -2, 1, 3, 4, 5}));

            arr = {1};
            QuickSort(arr);
            assert(arr == std::vector<int>({1}));

            arr = {20, 3};
            QuickSort(arr);
            assert(arr == std::vector<int>({3, 20}));

            arr = {3, 3, 3, 20, 7, 3};
            QuickSort(arr);
            assert(arr == std::vector<int>({3, 3, 3, 3, 7, 20}));

            arr = {3, 20, 7, 1};
            QuickSort(arr);
            assert(arr == std::vector<int>({1, 3, 7, 20}));

            std::cout << "All tests passed" << std::endl;
        }
    }
}
