#include <iostream>
#include <vector>
#include <cassert>

namespace finding_last_zero
{
    int FindingLastZero(const std::vector<int> &arr, int left, int right);

    // Input: A[:k] = 0, A[k+1:] = 1
    int FindingLastZero(const std::vector<int> &arr)
    {
        int left = 0, right = arr.size() - 1;

        return FindingLastZero(arr, left, right);
    }

    int FindingLastZero(const std::vector<int> &arr, int left, int right)
    {
        if (left > right)
            return -1;
        if (left == right)
            return arr[left] == 0 ? left : -1;
        if (left + 1 == right)
            return arr[right] == 0 ? right : (arr[left] == 0 ? left : -1);

        int mid = left + (right - left) / 2;

        if (arr[mid] == 1)
            return FindingLastZero(arr, left, mid - 1);
        // arr[mid] == 0
        if (arr[mid + 1] == 1)
            return mid;

        if (arr[right] == 0)
            return right;
        else
            return FindingLastZero(arr, mid, right);
    }

    void Test()
    {
        std::vector<int> arr = {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1};
        assert(FindingLastZero(arr) == 3);

        arr = {0, 0, 0, 0};
        assert(FindingLastZero(arr) == 3);

        arr = {1, 1, 1, 1};
        assert(FindingLastZero(arr) == -1);

        arr = {0, 0, 0, 0, 0, 1, 1};
        assert(FindingLastZero(arr) == 4);

        arr = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1};
        assert(FindingLastZero(arr) == 5);
    }
}
