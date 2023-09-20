#include <iostream>
#include <vector>
#include <cassert>

namespace divide_and_conquer
{
    namespace binary_search
    {
        int BinarySearch(const std::vector<int> &sorted_array, int target, int left, int right);

        int BinarySearch(const std::vector<int> &sorted_array, int target)
        {
            int left = 0;
            int right = sorted_array.size() - 1;

            return BinarySearch(sorted_array, target, left, right);
        }

        int BinarySearch(const std::vector<int> &sorted_array, int target, int left, int right)
        {
            if (left > right)
                return -1;

            int mid = left + (right - left) / 2;
            if (sorted_array[mid] == target)
                return mid;
            else if (sorted_array[mid] < target)
                return BinarySearch(sorted_array, target, mid + 1, right);
            else
                return BinarySearch(sorted_array, target, left, mid - 1);
        }

        void Test()
        {
            const std::vector<int> sorted_array = {-6, -2, 1, 3, 4, 5};
            assert(BinarySearch(sorted_array, -6) == 0);
            assert(BinarySearch(sorted_array, -2) == 1);
            assert(BinarySearch(sorted_array, 1) == 2);
            assert(BinarySearch(sorted_array, 3) == 3);
            assert(BinarySearch(sorted_array, 4) == 4);
            assert(BinarySearch(sorted_array, 5) == 5);
            assert(BinarySearch(sorted_array, 0) == -1);
            assert(BinarySearch(sorted_array, 6) == -1);

            std::cout << "All tests passed" << std::endl;
        }
    }
}
