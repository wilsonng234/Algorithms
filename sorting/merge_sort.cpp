#include <iostream>
#include <vector>
#include <cassert>

namespace sorting
{
    namespace merge_sort
    {
        // O(n^2)
        void InPlaceMerge(std::vector<int> &arr, int start, int mid, int end)
        {
            int i = start, j = mid + 1;

            while (i <= mid && j <= end)
            {
                if (arr[i] <= arr[j])
                    i++;
                else
                {
                    int smallest_value = arr[j];
                    int smallest_idx = j;

                    while (smallest_idx > i)
                    {
                        arr[smallest_idx] = arr[smallest_idx - 1];
                        smallest_idx--;
                    }

                    arr[i] = smallest_value;
                    i++;
                    mid++;
                    j++;
                }
            }
        }

        // O(n)
        void Merge(std::vector<int> &arr, int start, int mid, int end)
        {
            std::vector<int> left(arr.begin() + start, arr.begin() + mid + 1);
            std::vector<int> right(arr.begin() + mid + 1, arr.begin() + end + 1);

            int i = 0, j = 0, k = start;

            while (k <= end)
            {
                if (i >= left.size())
                    arr[k++] = right[j++];
                else if (j >= right.size())
                    arr[k++] = left[i++];
                else
                {
                    if (left[i] <= right[j])
                        arr[k++] = left[i++];
                    else
                        arr[k++] = right[j++];
                }
            }
        }

        void MergeSort(std::vector<int> &arr, int start, int end);

        void MergeSort(std::vector<int> &arr)
        {
            MergeSort(arr, 0, arr.size() - 1);
        }

        // T(n) = 2T(n/2) + n
        void MergeSort(std::vector<int> &arr, int start, int end)
        {
            if (start == end)
                return;

            int mid = start + (end - start) / 2;
            MergeSort(arr, start, mid);
            MergeSort(arr, mid + 1, end);
            Merge(arr, start, mid, end);
        }

        void Test()
        {
            std::vector<int> arr = {5, -2, 4, -6, 1, 3};
            MergeSort(arr);
            assert(arr == std::vector<int>({-6, -2, 1, 3, 4, 5}));

            arr = {1};
            MergeSort(arr);
            assert(arr == std::vector<int>({1}));

            arr = {20, 3};
            MergeSort(arr);
            assert(arr == std::vector<int>({3, 20}));

            arr = {3, 20, 7};
            MergeSort(arr);
            assert(arr == std::vector<int>({3, 7, 20}));

            arr = {3, 20, 7, 1};
            MergeSort(arr);
            assert(arr == std::vector<int>({1, 3, 7, 20}));

            std::cout << "All tests passed" << std::endl;
        }
    }
}
