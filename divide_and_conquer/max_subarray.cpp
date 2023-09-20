#include <iostream>
#include <vector>
#include <cassert>

namespace max_subarray
{
    int MaxSubarray(const std::vector<int> &arr, int start, int end);

    int MaxSubarray(const std::vector<int> &arr)
    {
        return MaxSubarray(arr, 0, arr.size() - 1);
    }

    int Merge(const std::vector<int> &arr, int start, int mid, int end)
    {
        int left = arr[mid], max_left = arr[mid];
        int right = arr[mid + 1], max_right = arr[mid + 1];

        for (int i = mid - 1; i >= start; i--)
        {
            left += arr[i];
            max_left = std::max(max_left, left);
        }

        for (int i = mid + 2; i <= end; i++)
        {
            right += arr[i];
            max_right = std::max(max_right, right);
        }

        return max_left + max_right;
    }

    int MaxSubarray(const std::vector<int> &arr, int start, int end)
    {
        if (start == end)
            return arr[start];

        int mid = start + (end - start) / 2;

        int left = MaxSubarray(arr, start, mid);
        int right = MaxSubarray(arr, mid + 1, end);
        int left_right = Merge(arr, start, mid, end);

        return std::max(std::max(left, right), left_right);
    };

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
