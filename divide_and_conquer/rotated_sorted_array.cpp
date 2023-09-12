#include <iostream>
#include <vector>

int IndexOfRotation(const std::vector<int> &rotated_sorted_array, int left, int right);

// Same as index of maximum element
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

int main()
{
    std::vector<int> rotatedSortedArray = {4};
    std::cout << IndexOfRotation(rotatedSortedArray) << std::endl;

    rotatedSortedArray = {4, 5};
    std::cout << IndexOfRotation(rotatedSortedArray) << std::endl;

    rotatedSortedArray = {4, 5, 6};
    std::cout << IndexOfRotation(rotatedSortedArray) << std::endl;

    rotatedSortedArray = {4, 5, 6, 7};
    std::cout << IndexOfRotation(rotatedSortedArray) << std::endl;

    rotatedSortedArray = {4, 5, 6, 7, 0};
    std::cout << IndexOfRotation(rotatedSortedArray) << std::endl;

    rotatedSortedArray = {4, 5, 6, 7, 0, 1};
    std::cout << IndexOfRotation(rotatedSortedArray) << std::endl;

    rotatedSortedArray = {4, 5, 6, 7, 0, 1, 2};
    std::cout << IndexOfRotation(rotatedSortedArray) << std::endl;

    rotatedSortedArray = {4, 5, 6, 7, 0, 1, 2, 3};
    std::cout << IndexOfRotation(rotatedSortedArray) << std::endl;

    return 0;
}