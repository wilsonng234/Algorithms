#include <iostream>
#include <vector>
#include <cassert>

namespace inversion_count
{
    int InversionCount(std::vector<int> &arr, int start, int end);

    int InversionCount(std::vector<int> &arr)
    {
        return InversionCount(arr, 0, arr.size() - 1);
    }

    int MergeAndCount(std::vector<int> &arr, int start, int mid, int end)
    {
        std::vector<int> left(arr.begin() + start, arr.begin() + mid + 1);
        std::vector<int> right(arr.begin() + mid + 1, arr.begin() + end + 1);

        int i = 0, j = 0, k = start;
        int count = 0;

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
                {
                    count += left.size() - i;
                    arr[k++] = right[j++];
                }
            }
        }

        return count;
    }

    int InversionCount(std::vector<int> &arr, int start, int end)
    {
        if (start == end)
            return 0;

        int mid = start + (end - start) / 2;

        int left = InversionCount(arr, start, mid);
        int right = InversionCount(arr, mid + 1, end);
        int left_right = MergeAndCount(arr, start, mid, end);

        return left + right + left_right;
    };

    void Test()
    {
        std::vector<int> arr = {5, -2, 4, -6, 1, 3};
        assert(InversionCount(arr) == 9);

        arr = {3, 7, 10, 14, 18, 19, 2, 11, 16, 17, 23, 25};
        assert(InversionCount(arr) == 13);

        arr = {1};
        assert(InversionCount(arr) == 0);

        arr = {20, 3};
        assert(InversionCount(arr) == 1);

        arr = {3, 20, 7};
        assert(InversionCount(arr) == 1);

        arr = {3, 20, 7, 1};
        assert(InversionCount(arr) == 4);

        std::cout << "All tests passed" << std::endl;
    }
}
