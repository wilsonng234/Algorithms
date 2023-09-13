#include <iostream>
#include <vector>
#include <cassert>

#include "binary_search.cpp"

namespace rotated_sorted_array
{
    int IndexOfRotation(const std::vector<int> &rotated_sorted_array, int left, int right);

    // Input: A[:k+1] is sorted, A[k+1:] is sorted, A[k] is the maximum element (k == index of rotation)
    int IndexOfRotation(const std::vector<int> &rotated_sorted_array)
    {
        int left = 0;
        int right = rotated_sorted_array.size() - 1;

        return IndexOfRotation(rotated_sorted_array, left, right);
    }

    int IndexOfRotation(const std::vector<int> &rotated_sorted_array, int left, int right)
    {
        if (left >= right)
            return -1;

        int mid = left + (right - left) / 2;

        if (rotated_sorted_array[left] > rotated_sorted_array[mid])
            return IndexOfRotation(rotated_sorted_array, left, mid - 1);
        if (rotated_sorted_array[left] < rotated_sorted_array[mid])
        {
            if (rotated_sorted_array[mid] > rotated_sorted_array[mid + 1])
                return mid;
            else
                return IndexOfRotation(rotated_sorted_array, mid, right);
        }

        return -1;
    }

    int FindX(const std::vector<int> &rotated_sorted_array, int x)
    {
        int index_of_rotation = IndexOfRotation(rotated_sorted_array);

        if (x >= rotated_sorted_array[0])
            return binary_search::BinarySearch(rotated_sorted_array, x, 0, index_of_rotation);
        else
            return binary_search::BinarySearch(rotated_sorted_array, x, index_of_rotation + 1, rotated_sorted_array.size() - 1);
    }

    void Test()
    {
        std::vector<int> rotatedSortedArray = {4};
        assert(IndexOfRotation(rotatedSortedArray) == -1);

        rotatedSortedArray = {4, 5};
        assert(IndexOfRotation(rotatedSortedArray) == -1);

        rotatedSortedArray = {4, 5, 6};
        assert(IndexOfRotation(rotatedSortedArray) == -1);

        rotatedSortedArray = {4, 5, 6, 7};
        assert(IndexOfRotation(rotatedSortedArray) == -1);

        rotatedSortedArray = {4, 5, 6, 7, 0};
        assert(IndexOfRotation(rotatedSortedArray) == 3);

        rotatedSortedArray = {4, 5, 6, 7, 0, 1};
        assert(IndexOfRotation(rotatedSortedArray) == 3);

        rotatedSortedArray = {4, 5, 6, 7, 0, 1, 2};
        assert(IndexOfRotation(rotatedSortedArray) == 3);

        rotatedSortedArray = {4, 5, 6, 7, 0, 1, 2, 3};
        assert(IndexOfRotation(rotatedSortedArray) == 3);

        assert(FindX(rotatedSortedArray, 4) == 0);
        assert(FindX(rotatedSortedArray, 5) == 1);
        assert(FindX(rotatedSortedArray, 6) == 2);
        assert(FindX(rotatedSortedArray, 7) == 3);
        assert(FindX(rotatedSortedArray, 0) == 4);
        assert(FindX(rotatedSortedArray, 1) == 5);
        assert(FindX(rotatedSortedArray, 2) == 6);
        assert(FindX(rotatedSortedArray, 3) == 7);
        assert(FindX(rotatedSortedArray, 8) == -1);

        std::cout << "All tests passed" << std::endl;
    }
}
